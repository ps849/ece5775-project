#include "haar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(MyRect* rectList,int *rectList_size,int * labels,int *labels_size , float eps);//(MyRect* _vec,int * _vec std::vector<int>& labels, float eps);

int myMax(int a, int b)
{
  if (a >= b)
    return a;
  else
    return b;
}

int myMin(int a, int b)
{
  if (a <= b)
    return a;
  else
    return b;
}

inline  int  myRound( float value )
{
  return (int)(value + (value >= 0 ? 0.5 : -0.5));
}

int myAbs(int n)
{
  if (n >= 0)
    return n;
  else
    return -n;
}

int predicate(float eps, MyRect& r1, MyRect& r2)// returns true if the rectangles overalp
{
  float delta = eps*(myMin(r1.width, r2.width) + myMin(r1.height, r2.height))*0.5; // finding out some threshold to merge to overalapping rectangles
  return myAbs(r1.x - r2.x) <= delta &&
    myAbs(r1.y - r2.y) <= delta &&
    myAbs(r1.x + r1.width - r2.x - r2.width) <= delta &&
    myAbs(r1.y + r1.height - r2.y - r2.height) <= delta;
}

void groupRectangles(MyRect *rectList, int *rectList_size, int groupThreshold, float eps)//(std::vector<MyRect>& rectList, int groupThreshold, float eps)
{
  if( groupThreshold <= 0 || *rectList_size==0 )
    return;


  //std::vector<int> labels;
   int labels[500];
   int labels_size=0;
   int flag=0;
 //  int counter=*rectList_size;

  //int nclasses = partition(rectList, labels, eps);
  int nclasses = partition(rectList, rectList_size, labels, &labels_size , eps); // tells how many distinct rectangles are there
  printf("\nnclasses = %d",nclasses);
  
  printf("\n\nAfter partition result_size detect obj = %d",*rectList_size);
for(int i=0 ; i<*rectList_size;i++)
   printf("\n labels = %d rects %d %d %d %d",labels[i],rectList[i].x,rectList[i].y,rectList[i].width,rectList[i].height);
  
  
  ////// For Scientist Picture ////////////
  //nclasses=29; // IT is total no of faces on the picture
  ////////////////////////////////////////
  
  
 // std::vector<MyRect> rrects(nclasses);
 // std::vector<int> rweights(nclasses);
   MyRect rrects[500];
   int rrects_size=0;
   int rweights[500];
   int rweights_size=0;
   rrects_size=nclasses;
   rweights_size=nclasses;

  int i, j, nlabels = labels_size;//<500 ? labels_size : 0;//(int)labels.size();


  for(int i =0;i<500;i++)
  {
    rweights[i]=0;
    rrects[i].x=0;
    rrects[i].y=0;
    rrects[i].width=0;
    rrects[i].height=0;
    
   }
   
  printf("\n nlabels = %d",nlabels);
  for( i = 0; i < nlabels; i++ )
    {
      #pragma HLS loop_tripcount max=20
      int cls = labels[i];
      rrects[cls].x += rectList[i].x;
      rrects[cls].y += rectList[i].y;
      rrects[cls].width += rectList[i].width;
      rrects[cls].height += rectList[i].height;
      rweights[cls]++;
      printf("\n rwt[%d] = %d",cls,rweights[cls]);
    }
  for( i = 0; i < nclasses; i++ )
    {
      #pragma HLS loop_tripcount max=2
      MyRect r = rrects[i];
      float s = 1.f/rweights[i];
      rrects[i].x = myRound(r.x*s);
      rrects[i].y = myRound(r.y*s);
      rrects[i].width = myRound(r.width*s);
      rrects[i].height = myRound(r.height*s);
      printf(" \n rrect %d %d %d %d %f",rrects[i].x ,rrects[i].y,rrects[i].width,rrects[i].height,s);

    }

   *rectList_size=0;
  //rectList.clear();

  for( i = 0; i < nclasses; i++ )
    {
      #pragma HLS loop_tripcount max=2
      MyRect r1 = rrects[i];
      int n1 = rweights[i];
      //if( n1 <= groupThreshold )
	    //continue;
	  if(!( n1 <= groupThreshold )){
      /* filter out small face rectangles inside large rectangles */
      flag = 0;
      for( j = 0; j < nclasses; j++ )
        {
          #pragma HLS loop_tripcount max=2
           int n2,dx,dy;
           MyRect r2;
           if(flag==0){
                  	  n2 = rweights[j];
                  	  /*********************************
                  	   * if it is the same rectangle, 
                  	   * or the number of rectangles in class j is < group threshold, 
                  	   * do nothing 
                  	   ********************************/
                  	  //if( j == i || n2 <= groupThreshold )
                  	    //continue;
                  	 
                  	    if(!( j == i || n2 <= groupThreshold )){
                  	  r2 = rrects[j];

                  	  dx = myRound( r2.width * eps );
                  	  dy = myRound( r2.height * eps );
                       }
      	  if( i != j &&
      	      r1.x >= r2.x - dx &&
      	      r1.y >= r2.y - dy &&
      	      r1.x + r1.width <= r2.x + r2.width + dx &&
      	      r1.y + r1.height <= r2.y + r2.height + dy &&
      	      (n2 > myMax(3, n1) || n1 < 3) )
      	    //break;
      	    flag=1;//  j=nclasses+2; // to break the loop
      	    
        }} // end of inner for loop

            if( j == nclasses )
              {
      	  //rectList.push_back(r1); // insert back r1
                rectList[*rectList_size]=r1;
                *rectList_size=*rectList_size+1;
              }
    }} // end of outer for loop 

} // end of function

/*
int partition(MyRect *vec,int *vec_size, int  *labels,int *labels_size, float eps)//(std::vector<MyRect>& _vec, std::vector<int>& labels, float eps)
{
  int i, j, N = *vec_size;//vec[49];// (int)_vec.size();
  printf("\n N = %d \n\n",N);

  //N=341; // for Scientist picture

  const int PARENT=0;
  const int RANK=1;

  //std::vector<int> _nodes(N*2);
  int _nodes[1000];

  int (*nodes)[2] = (int(*)[2])&_nodes[0];
  int loop_counter = 0;
  int max_2_1=0;
  int max_2_2_1=0;
  int max_2_2_2=0;
  int max_2_2_3=0;
  int max_3_1=0;
  
  for(int i=0 ; i<100; i++)
    _nodes[i]=0;

  // The first O(N) pass: create N single-vertex trees 
L1:for(i = 0; i < N; i++) 
    {
      #pragma HLS loop_tripcount max=20
      #pragma HLS pipeline
      nodes[i][PARENT]=-1;
      nodes[i][RANK] = 0;
    }

  // The main O(N^2) pass: merge connected components 
L2:for( i = 0; i < N; i++ ) 
    {
      #pragma HLS loop_tripcount max=20
      #pragma HLS pipeline
      
      int root = i;

      // find root 
 	    loop_counter=0;
 L2_1:while( nodes[root][PARENT] >= 0 ) // for each node climbing up in the tree until  we find the root of the tree in which this node lies
	    {
	      root = nodes[root][PARENT];
        loop_counter++;
      }
      if(max_2_1 < loop_counter) max_2_1 = loop_counter;
      
      
 L2_2:for( j = 0; j < N; j++ )
	    {
	      if( i == j || !predicate(eps, vec[i], vec[j]))
	      continue;
	      int root2 = j;
	      
	      loop_counter=0;
 L2_2_1:while( nodes[root2][PARENT] >= 0 )
        {
	        root2 = nodes[root2][PARENT];
	        loop_counter++;
	      }
	      if(max_2_2_1 < loop_counter) max_2_2_1 = loop_counter;
		    
		      
	      if( root2 != root )
	      {
	      // unite both trees 
	        int rank = nodes[root][RANK], rank2 = nodes[root2][RANK];
	        if( rank > rank2 )
		        nodes[root2][PARENT] = root;
	        else
		      {
      		  nodes[root][PARENT] = root2;
      		  nodes[root2][RANK] += rank == rank2;
      		  root = root2;
		      }

	        int k = j, parent;

	      // compress the path from node2 to root 
	        loop_counter=0;
   L2_2_2:while( (parent = nodes[k][PARENT]) >= 0 )
		      {
		        nodes[k][PARENT] = root;
		        k = parent;
		        loop_counter++;
		      }
		      if(max_2_2_2 < loop_counter) max_2_2_2 = loop_counter;
		     

	      // compress the path from node to root 
	        k = i;
	        loop_counter=0;
   L2_2_3:while( (parent = nodes[k][PARENT]) >= 0 )
		     {
		       nodes[k][PARENT] = root;
		       k = parent;
		       loop_counter++;
		     }
		     if(max_2_2_3 < loop_counter) max_2_2_3 = loop_counter;
		    		     
		     
	      }//end of if
	    } // end of inner for loop
    }  // end of outer for loop

   printf("\nLoop counter Partition() L2_1 = %d",max_2_1);
   printf("\nLoop counter Partition() L2_2_1 = %d",max_2_2_1);
   printf("\nLoop counter Partition() L2_2_2 = %d",max_2_2_2);
   printf("\nLoop counter Partition() L2_2_3 = %d",max_2_2_3);
   
  ///////////    Final O(N) pass: enumerate classes ///////////
  //labels.resize(N);
  *labels_size=N;

  int nclasses = 0;

  for( i = 0; i < N; i++ )
    {
      int root = i;
      loop_counter=0;
      while( nodes[root][PARENT] >= 0 )
      {
	      root = nodes[root][PARENT];
	      loop_counter++;
	    }
	    if(max_3_1 < loop_counter) max_3_1 = loop_counter; 
      ////// re-use the rank as the class label ///////
      if( nodes[root][RANK] >= 0 )
	       nodes[root][RANK] = ~nclasses++;
      labels[i] = ~nodes[root][RANK];
    }
    printf("\nLoop counter Partition() L_3_1 = %d",max_3_1);

  return nclasses;
}

*/



int partition(MyRect *vec,int *vec_size, int  *labels,int *labels_size, float eps)//(std::vector<MyRect>& _vec, std::vector<int>& labels, float eps)
{
  int i, j, m, N = *vec_size;//vec[49];// (int)_vec.size();

  //////////////// for Scientist picture //////////////////
  //N=341; 
  int max_2_1=8;
  int max_2_2_1=8;
  int max_2_2_2=8;
  int max_2_2_3=8;
  /////////////////////////////////////////////////////////

  const int PARENT=0;
  const int RANK=1;

  //std::vector<int> _nodes(N*2);
  int _nodes[1000];

  int (*nodes)[2] = (int(*)[2])&_nodes[0];
 
  
  for(int i=0 ; i<1000; i++)
    _nodes[i]=0;

  // The first O(N) pass: create N single-vertex trees 
L1:for(i = 0; i < N; i++) 
    {
      #pragma HLS loop_tripcount max=20
      #pragma HLS pipeline
      nodes[i][PARENT]=-1;
      nodes[i][RANK] = 0;
    }
    
  // The main O(N^2) pass: merge connected components 
L2:for( i = 0; i < N; i++ ) 
    {
      #pragma HLS loop_tripcount max=20
      int root = i;

      // find root 
 L2_1:while( nodes[root][PARENT] >= 0 ) // for each node climbing up in the tree until  we find the root of the tree in which this node lies
    	    {
    	      #pragma HLS loop_tripcount max=2
    	      #pragma HLS pipeline
    	      root = nodes[root][PARENT];
          }
 
      
      
 L2_2:for( j = 0; j < N; j++ )
	    {
	       #pragma HLS loop_tripcount max=20
	      if( i == j || !predicate(eps, vec[i], vec[j]))
	      continue;  
	      int root2 = j;
	      
	      
 L2_2_1:while( nodes[root2][PARENT] >= 0 )
            {
              #pragma HLS loop_tripcount max=2
    	        root2 = nodes[root2][PARENT];
    	      }

		    
		     
	      if( root2 != root )
	      {
	      // unite both trees 
	        int rank = nodes[root][RANK], rank2 = nodes[root2][RANK];
	        if( rank > rank2 )
		        nodes[root2][PARENT] = root;
	        else
		      {
      		  nodes[root][PARENT] = root2;
      		  nodes[root2][RANK] += rank == rank2;
      		  root = root2;
		      }

	        int k = j, parent;

	      // compress the path from node2 to root 

   L2_2_2:while( (parent = nodes[k][PARENT]) >= 0 )
    		      {
    		        #pragma HLS loop_tripcount max=2
    		        nodes[k][PARENT] = root;
    		        k = parent;
    		      }
 
		     

	      // compress the path from node to root 
	        k = i;
 
   L2_2_3:while( (parent = nodes[k][PARENT]) >= 0 )
    		     {
    		       #pragma HLS loop_tripcount max=2
    		       nodes[k][PARENT] = root;
    		       k = parent;
    		     }
    		  //}

		    		     
		     
	      }//end of if
	    } // end of inner for loop
    }  // end of outer for loop

   
  ///////////    Final O(N) pass: enumerate classes ///////////
  //labels.resize(N);
  *labels_size=N;

  int nclasses = 0;

  for( i = 0; i < N; i++ )
    {
      #pragma HLS loop_tripcount max=20
      int root = i;
      while( nodes[root][PARENT] >= 0 )
      {
        #pragma HLS loop_tripcount max=2
	      root = nodes[root][PARENT];
	    }
	      
      ////// re-use the rank as the class label ///////
      if( nodes[root][RANK] >= 0 )
	       nodes[root][RANK] = ~nclasses++;
      labels[i] = ~nodes[root][RANK];
    }

  return nclasses;
}


/* draw white bounding boxes around detected faces */
void drawRectangle(MyInputImage* image,unsigned char Data[MAX_HEIGHT][MAX_WIDTH], MyRect r)
{
	int i;
	int col = image->width;
 printf("here in draw\n");
printf("drawing width is %d %d %d %d ", r.x,r.y,r.width,r.height);

	for (i = 0; i < r.width; i++)
	{//printf("drawing width is %d %d %d %d ", r.x,r,y,r.width,r.height);
      //image->data[col*r.y + r.x + i] = 255;
	//Data[col*r.y + r.x + i] = 255;
	      Data[r.y][r.x + i] = 255;
        }
	for (i = 0; i < r.height; i++)
	{
		//image->data[col*(r.y+i) + r.x + r.width] = 255;
               //  Data[col*(r.y+i) + r.x + r.width] = 255;
               Data[r.y+i][r.x + r.width] = 255;

	}
	for (i = 0; i < r.width; i++)
	{
		//image->data[col*(r.y + r.height) + r.x + r.width - i] = 255;
	//Data[col*(r.y + r.height) + r.x + r.width - i] = 255;
	Data[r.y + r.height][r.x + r.width - i] = 255;
        }
	for (i = 0; i < r.height; i++)
	{
		//image->data[col*(r.y + r.height - i) + r.x] = 255;
               // Data[col*(r.y + r.height - i) + r.x] = 255;
               Data[r.y + r.height - i][r.x] = 255;
	}

}
