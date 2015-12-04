#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "stdio-wrapper.h"
#include "haar.h"
#include "image.cpp"

#define TOTAL_NODES 2913
#define TOTAL_STAGES 25
#define TOTAL_COORDINATES TOTAL_NODES*12
#define TOTAL_WEIGHTS TOTAL_NODES*3
//#define MAX_HEIGHT 626
//#define MAX_WIDTH 1280
//#define MAX_IMAGE_SIZE 801280//MAX_HEIGHT*MAX_WIDTH


static int stages_array[TOTAL_STAGES];
static int rectangles_array[TOTAL_COORDINATES];
static int weights_array[TOTAL_WEIGHTS];
static int alpha1_array[TOTAL_NODES];
static int alpha2_array[TOTAL_NODES];
static int tree_thresh_array[TOTAL_NODES];
static int stages_thresh_array[TOTAL_STAGES];



void readTextClassifier()//(myCascade * cascade)
{
  /*number of stages of the cascade classifier*/
  int stages;
  /*total number of weak classifiers (one node each)*/
  int total_nodes = 0;
  int i, j, k, l;
  char mystring [12];
  int r_index = 0;
  int w_index = 0;
  int tree_index = 0;
  FILE *finfo = fopen("info.txt", "r");  // it consists of number of haar classifiers in each of the 25 cacade blocks
 // FILE *out_file = fopen("haar_data2.h","w");
  FILE *out_fileEWC = fopen("haar_dataEWC_with_partitioning.h","w");
  FILE *out_fileRcc = fopen("haar_dataRcc_with_partitioning.h","w");
  /**************************************************
  /* how many stages are in the cascaded filter? 
  /* the first line of info.txt is the number of stages 
  /* (in the 5kk73 example, there are 25 stages)
  **************************************************/
  if ( fgets (mystring , 12 , finfo) != NULL ) // read the number of stages in mystring assumed can be at max 12 characters
    {
      stages = atoi(mystring);
    }
  i = 0;

  //stages_array = (int *)malloc(sizeof(int)*stages); // ARM core can output the max number of stages for all and in fpga use that much space
  //int stages_array[TOTAL_STAGES];
  /**************************************************
   * how many filters in each stage? 
   * They are specified in info.txt,
   * starting from second line.
   * (in the 5kk73 example, from line 2 to line 26)
   *************************************************/
  while ( fgets (mystring , 12 , finfo) != NULL ) // keep on reading the next lines until EOF is reached these lines have no. of filters in each stage
    {
      stages_array[i] = atoi(mystring); // stores the number of filters in each stage
     // fprintf(out_file, "stages_array[%d] = %d;\n",i,atoi(mystring));
      total_nodes += stages_array[i];  // total no. of filters
      i++;
    }
  fclose(finfo);

  printf("total_nodes=%d",total_nodes);

  /* TODO: use matrices where appropriate */
  /***********************************************
   * Allocate a lot of array structures
   * Note that, to increase parallelism,
   * some arrays need to be splitted or duplicated
   **********************************************/
  //rectangles_array = (int *)malloc(sizeof(int)*total_nodes*12); // each rectangle will be of size 12 integer elements (So 12 elements for each filter)
   
  //int rectangles_array[TOTAL_NODES];
  //scaled_rectangles_array = (int **)malloc(sizeof(int*)*total_nodes*12); // an array of pointers to access each of the element
  //weights_array = (int *)malloc(sizeof(int)*total_nodes*3); // in current implementation only 3 different possible regions so 3 weights for each filter
  //int weights_array[TOTAL_WEIGHTS];

//  alpha1_array = (int*)malloc(sizeof(int)*total_nodes); // for each filter one alpha1
//  alpha2_array = (int*)malloc(sizeof(int)*total_nodes); // for each filetr one alpha2
//  tree_thresh_array = (int*)malloc(sizeof(int)*total_nodes); // for each filter one threshold value
//  stages_thresh_array = (int*)malloc(sizeof(int)*stages);  // each stage also has a threshold value

   //int alpha1_array[TOTAL_NODES];
   //int alpha2_array[TOTAL_NODES];
   //int tree_thresh_array[TOTAL_NODES];
   //int stages_thresh_array[TOTAL_STAGES];
  FILE *fp = fopen("class.txt", "r");

  /******************************************
   * Read the filter parameters in class.txt
   *
   * Each stage of the cascaded filter has:
   * 18 parameter per filter x filter per stage
   * + 1 threshold per stage
   *
   * For example, in 5kk73, 
   * the first stage has 9 filters,
   * the first stage is specified using
   * 18 * 9 + 1 = 163 parameters
   * They are line 1 to 163 of class.txt
   *
   * The 18 parameters for each filter are:
   * 1 to 4: coordinates of rectangle 1
   * 5: weight of rectangle 1
   * 6 to 9: coordinates of rectangle 2
   * 10: weight of rectangle 2
   * 11 to 14: coordinates of rectangle 3
   * 15: weight of rectangle 3
   * 16: threshold of the filter
   * 17: alpha 1 of the filter
   * 18: alpha 2 of the filter
   ******************************************/

  /* loop over n of stages */
  for (i = 0; i < stages; i++)
    {    /* loop over n of trees */
      for (j = 0; j < stages_array[i]; j++) // number of filters in each stage
	{	/* loop over n of rectangular features */
	  for(k = 0; k < 3; k++)
	    {	/* loop over the n of vertices */
	      for (l = 0; l <4; l++)
		{
		  if (fgets (mystring , 12 , fp) != NULL)
                    {
		    rectangles_array[r_index] = atoi(mystring); // stores all the rectangle cordinates in all the filters in all stages
                   // fprintf(out_file, "rectangles_array[%d] = %d;\n",r_index,atoi(mystring));
                    }
		  else
		    break;
		  r_index++;
		} /* end of l loop */
	      if (fgets (mystring , 12 , fp) != NULL)
		{
		  weights_array[w_index] = atoi(mystring);
                 // fprintf(out_file, "weights_array[%d] = %d;\n",w_index,atoi(mystring));
		  /* Shift value to avoid overflow in the haar evaluation */
		  /*TODO: make more general */
		  /*weights_array[w_index]>>=8; */
		}
	      else
		break;
	      w_index++;
	    } /* end of k loop */
	  if (fgets (mystring , 12 , fp) != NULL)
            {
	    tree_thresh_array[tree_index]= atoi(mystring);
           // fprintf(out_file, "tree_thresh_array[%d] = %d;\n",tree_index,atoi(mystring));
	    }
          else
	    break;
	  if (fgets (mystring , 12 , fp) != NULL)
            {
	    alpha1_array[tree_index]= atoi(mystring);
           // fprintf(out_file, "alpha1_array[%d] = %d;\n",tree_index,atoi(mystring));
            }
	  else
	    break;
	  if (fgets (mystring , 12 , fp) != NULL)
            {
	    alpha2_array[tree_index]= atoi(mystring);
           // fprintf(out_file, "alpha2_array[%d] = %d;\n",tree_index,atoi(mystring));
            }
	  else
	    break;
	  tree_index++;
	  if (j == stages_array[i]-1)  // if at the last filter
	    {
	      if (fgets (mystring , 12 , fp) != NULL)
                {
		stages_thresh_array[i] = atoi(mystring);  // store the threshold value for the stage
               // fprintf(out_file, "stages_thresh_array[%d] = %d;\n",i,atoi(mystring));
                }
	      else
		break;
	    }
	} /* end of j loop */
    } /* end of i loop */
  

fprintf(out_fileRcc, "  int stages_array[%d] = {\n",TOTAL_STAGES);

for(int i=0;i<TOTAL_STAGES;i++)
{
  if(i!=TOTAL_STAGES-1)
    fprintf(out_fileRcc, "%d,",stages_array[i]);
  else 
    fprintf(out_fileRcc, "%d\n};\n",stages_array[i]);
}
/*
fprintf(out_fileRcc, "  int rectangles_array[%d][%d] = {\n",TOTAL_NODES, 12);

for(int i=0;i<TOTAL_NODES;i++)
{
  for(int j=0; j< 12; j++)
  {
   if(j==0)
     fprintf(out_fileRcc, "{%d,",rectangles_array[(i*12 + j)]);
   else if(i!=TOTAL_NODES-1 && j==11)
     fprintf(out_fileRcc, "%d},\n",rectangles_array[(i*12 + j)]);
   else if(i==TOTAL_NODES-1 && j==11)
     fprintf(out_fileRcc, "%d}}\n",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   }
}

fprintf(out_fileEWC, "  int weights_array[%d][%d] = {\n",TOTAL_NODES, 3);

for(int i=0;i<TOTAL_NODES;i++)
{
  for(int j=0; j< 3; j++)
  {
   if(j==0)
     fprintf(out_fileEWC, "{%d,",weights_array[(i*3 + j)]);
   else if(i!=TOTAL_NODES-1 && j==2)
     fprintf(out_fileEWC, "%d},\n",weights_array[(i*3 + j)]);
   else if(i==TOTAL_NODES-1 && j==2)
     fprintf(out_fileEWC, "%d}};\n",weights_array[(i*3 + j)]);
   else
     fprintf(out_fileEWC, "%d,",weights_array[(i*3 + j)]);
   }
}*/
//int j;
fprintf(out_fileRcc, "  int rectangles_array0[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=0;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array1[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=1;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array2[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=2;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array3[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=3;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array4[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=4;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array5[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=5;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array6[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=6;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array7[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=7;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array8[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=8;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array9[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=9;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array10[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=10;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}

fprintf(out_fileRcc, "  int rectangles_array11[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=11;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileRcc, "%d,",rectangles_array[(i*12 + j)]);
   else
     fprintf(out_fileRcc, "%d};\n\n",rectangles_array[(i*12 + j)]);
   
}


fprintf(out_fileEWC, "  int weights_array0[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=0;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileEWC, "%d,",weights_array[(i*3 + j)]);
   else
     fprintf(out_fileEWC, "%d};\n\n",weights_array[(i*3 + j)]);
}

fprintf(out_fileEWC, "  int weights_array1[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=1;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileEWC, "%d,",weights_array[(i*3 + j)]);
   else
     fprintf(out_fileEWC, "%d};\n\n",weights_array[(i*3 + j)]);
}

fprintf(out_fileEWC, "  int weights_array2[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
   j=2;
   if(i!=TOTAL_NODES-1)
     fprintf(out_fileEWC, "%d,",weights_array[(i*3 + j)]);
   else
     fprintf(out_fileEWC, "%d};\n\n",weights_array[(i*3 + j)]);
}

fprintf(out_fileEWC, "  int alpha1_array[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
  if(i!=TOTAL_NODES-1)
    fprintf(out_fileEWC, "%d,",alpha1_array[i]);
  else 
    fprintf(out_fileEWC, "%d\n};\n",alpha1_array[i]);
}

fprintf(out_fileEWC, "  int alpha2_array[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
  if(i!=TOTAL_NODES-1)
    fprintf(out_fileEWC, "%d,",alpha2_array[i]);
  else 
    fprintf(out_fileEWC, "%d\n};\n",alpha2_array[i]);
}


fprintf(out_fileEWC, "  int tree_thresh_array[%d] = {\n",TOTAL_NODES);

for(int i=0;i<TOTAL_NODES;i++)
{
  if(i!=TOTAL_NODES-1)
    fprintf(out_fileEWC, "%d,",tree_thresh_array[i]);
  else 
    fprintf(out_fileEWC, "%d\n};\n",tree_thresh_array[i]);
}

fprintf(out_fileRcc, "  int stages_thresh_array[%d] = {\n",TOTAL_STAGES);

for(int i=0;i<TOTAL_STAGES;i++)
{
  if(i!=TOTAL_STAGES-1)
    fprintf(out_fileRcc, "%d,",stages_thresh_array[i]);
  else 
    fprintf(out_fileRcc, "%d\n};\n",stages_thresh_array[i]);
}



fclose(fp);
//fclose(out_file);
fclose(out_fileEWC);
fclose(out_fileRcc);
}



int main()
{
  readTextClassifier();
  return 0;
}
