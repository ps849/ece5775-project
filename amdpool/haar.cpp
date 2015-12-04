#include "haar.h"

#define TOTAL_NODES 2913
#define TOTAL_STAGES 25
#define TOTAL_COORDINATES TOTAL_NODES*12
#define TOTAL_WEIGHTS TOTAL_NODES*3
#define MAX_HEIGHT 60
#define MAX_WIDTH 60
#define MAX_IMAGE_SIZE 3600

/****************************************************************************************/
/* DECLARATION OF FUNCTIONS 
****************************************************************************************/
void nearestNeighbor    ( MyInputImage *src,
                          unsigned char Data[MAX_HEIGHT][MAX_WIDTH],
                          MyImage *dst,
                          unsigned char IMG1_data[MAX_HEIGHT][MAX_WIDTH] 
                        );
 
void integralImages     ( MyImage *src,
                          unsigned char IMG1_data[MAX_HEIGHT][MAX_WIDTH],
                          MyIntImage *sum,
                          int SUM1_data[MAX_HEIGHT][MAX_WIDTH],
                          MyIntImage *sqsum,
                          int SQSUM1_data[MAX_HEIGHT][MAX_WIDTH]
                        );

void ScaleImage_Invoker ( float _factor,
                          int sum_row,
                          int sum_col,
                          MyRect *AllCandidates,
                          int *AllCandidates_size,
                          int SUM1_data[MAX_HEIGHT][MAX_WIDTH],
                          int SQSUM1_data[MAX_HEIGHT][MAX_WIDTH],
                          int rectangles_array0[2913],
                          int rectangles_array1[2913],
                          int rectangles_array2[2913],
                          int rectangles_array3[2913],
                          int rectangles_array4[2913],
                          int rectangles_array5[2913],
                          int rectangles_array6[2913],
                          int rectangles_array7[2913],
                          int rectangles_array8[2913], 
                          int rectangles_array9[2913], 
                          int rectangles_array10[2913], 
                          int rectangles_array11[2913],
                          int stages_array[25],
                          int stages_thresh_array[25],
                          int weights_array0[2913],
                          int weights_array1[2913],  
                          int weights_array2[2913],
                          int alpha1_array[2913],
                          int alpha2_array[2913],
                          int tree_thresh_array[2913]
                        );

int runCascadeClassifier( MyPoint pt,
                          int SUM1_data[MAX_HEIGHT][MAX_WIDTH],
                          int SQSUM1_data[MAX_HEIGHT][MAX_WIDTH], 
                          int rectangles_array0[2913],
                          int rectangles_array1[2913],
                          int rectangles_array2[2913],
                          int rectangles_array3[2913],
                          int rectangles_array4[2913],
                          int rectangles_array5[2913], 
                          int rectangles_array6[2913],
                          int rectangles_array7[2913],
                          int rectangles_array8[2913],
                          int rectangles_array9[2913],
                          int rectangles_array10[2913], 
                          int rectangles_array11[2913],
                          int stages_array[25],
                          int stages_thresh_array[25],
                          int weights_array0[2913], 
                          int weights_array1[2913], 
                          int weights_array2[2913],
                          int alpha1_array[2913], 
                          int alpha2_array[2913],
                          int tree_thresh_array[2913]
                        );

int evalWeakClassifier1 ( int variance_norm_factor,
                          int coord[12],
                          int filter_no,
                          int w_id, 
                          int weights_array0[2913],
                          int weights_array1[2913],
                          int weights_array2[2913],
                          int alpha1_array[2913],
                          int alpha2_array[2913],
                          int tree_thresh_array[2913]
                        );

void groupRectangles    ( MyRect *rectList, 
                          int *rectList_size, 
                          int groupThreshold, 
                          float eps
                        );

unsigned int int_sqrt   ( unsigned int value
                        );

int max                 ( int a, 
                          int b
                        );

int min                 ( int a, 
                          int b
                        );

inline  int  myRound ( float value )
{
  return (int)(value + (value >= 0 ? 0.5 : -0.5));
}

 /********************************************************
 * Function: detectObjects
 * Description: It calls all the major steps
 ******************************************************/

void detectObjects 

( unsigned char Data[60][60], 
  MyRect result[500],
  int *result_size
)

{
   #include "haar_dataRcc_with_partitioning.h"  
   #include "haar_dataEWC_with_partitioning.h"

   int iter_counter = 0;

   MyInputImage imgObj;
   MyInputImage *img= &imgObj;
   float  scaleFactor = 1.2;
   //int minNeighbors = 1;
   img->height = 60;
   img->width = 60;
   img->maxgrey = 255;
   img->flag  = 1;

  //float GROUP_EPS = 0.4;
  /***********************************
   * img1: normal image (unsigned char)
   * sum1: integral image (int)
   * sqsum1: square integral image (int)
   **********************************/
  MyImage image1Obj;  // Creating image objects to hold the properties like height width of image
  MyIntImage sum1Obj;
  MyIntImage sqsum1Obj;

  MyImage *img1 = &image1Obj; // Getting the pointers
  MyIntImage *sum1 = &sum1Obj;
  MyIntImage *sqsum1 = &sqsum1Obj;
 
  unsigned char IMG1_data[60][60];  
  int SUM1_data[60][60];
  int SQSUM1_data[60][60];

  float factor;

  MySize winSize0;
  winSize0.width = 24;
  winSize0.height= 24;

  img1->width = img->width;
  img1->height = img->height;
  img1->flag = 1;

  sum1->width = img->width;
  sum1->height = img->height;
  sum1->flag = 1;
    
  sqsum1->width = img->width;
  sqsum1->height = img->height;
  sqsum1->flag = 1;

  /* initial scaling factor */
  factor = 1;

L1: 
  for( iter_counter = 1;iter_counter<5 ; iter_counter++ )
  {
    // #pragma HLS pipeline

    /* size of the image scaled up */
    MySize winSize = { myRound(winSize0.width*factor), myRound(winSize0.height*factor) };
    /* size of the image scaled down (from bigger to smaller) */
    MySize sz = { ( img->width/factor ), ( img->height/factor ) };
    
    img1->height = sz.height;
    img1->width  = sz.width;

    sum1->height = sz.height;
    sum1->width  = sz.width;

    sqsum1->height = sz.height;
    sqsum1->width  = sz.width;
     
    nearestNeighbor ( img,
                      Data, 
                      img1,
                      IMG1_data
                    ); 

    integralImages ( img1,
                     IMG1_data, 
                     sum1,
                     SUM1_data,
                     sqsum1,
                     SQSUM1_data
                   ); /*** COMPUATATION INTENSIVE*****/  // sum1 is integral image and sum2 is sq integral image of the downsampled image img1 
      
    ScaleImage_Invoker ( factor, 
                         sum1->height, 
                         sum1->width,
                         result,
                         result_size, 
                         SUM1_data,
                         SQSUM1_data,
                         rectangles_array0,
                         rectangles_array1,
                         rectangles_array2,
                         rectangles_array3,
                         rectangles_array4,
                         rectangles_array5,
                         rectangles_array6,
                         rectangles_array7,
                         rectangles_array8,
                         rectangles_array9,
                         rectangles_array10,
                         rectangles_array11,
                         stages_array,
                         stages_thresh_array, 
                         weights_array0, 
                         weights_array1,
                         weights_array2, 
                         alpha1_array, 
                         alpha2_array,
                         tree_thresh_array
                       ); 
    factor *= scaleFactor;
  }//} /* end of the factor loop, finish all scales in pyramid*/

   /* if( minNeighbors != 0)
   {
     groupRectangles(result,result_size, minNeighbors, GROUP_EPS);
   }*/
}

void ScaleImage_Invoker 

( float _factor,
  int sum_row,
  int sum_col, 
  MyRect *AllCandidates, 
  int *AllCandidates_size, 
  int SUM1_data[MAX_HEIGHT][MAX_WIDTH], 
  int SQSUM1_data[MAX_HEIGHT][MAX_WIDTH],
  int rectangles_array0[2913],
  int rectangles_array1[2913], 
  int rectangles_array2[2913], 
  int rectangles_array3[2913], 
  int rectangles_array4[2913],
  int rectangles_array5[2913], 
  int rectangles_array6[2913],
  int rectangles_array7[2913],
  int rectangles_array8[2913], 
  int rectangles_array9[2913], 
  int rectangles_array10[2913], 
  int rectangles_array11[2913],
  int stages_array[25],
  int stages_thresh_array[25], 
  int weights_array0[2913],  
  int weights_array1[2913],  
  int weights_array2[2913], 
  int alpha1_array[2913], 
  int alpha2_array[2913],
  int tree_thresh_array[2913]
)
{
  float factor = _factor;
  MyPoint p;
  int result;
  int y2, x2, x, y, step;
  int x2_max,y2_max;
  
  ////////////// For 60 X 60 image /////////////////
  x2_max=36;
  y2_max=37;
  /////////////////////////////////////////////////////

 // MySize winSize0 = cascade->orig_window_size;
  MySize winSize0;
  winSize0.height = 24;
  winSize0.width  = 24;

  MySize winSize;

  winSize.width =  myRound(winSize0.width*factor); // scaling up the window
  winSize.height =  myRound(winSize0.height*factor);
 

  /********************************************
  * When filter window shifts to image boarder,
  * some margin need to be kept
  *********************************************/
  y2 = sum_row - winSize0.height; 
  x2 = sum_col - winSize0.width;  

  step = 1;
  /**********************************************
   * Shift the filter window over the image
   *********************************************/
  for( x = 0; x <= x2_max; x += step )
  {
    if(x <= x2)
    {
      for( y = 0; y <= y2_max; y += step ) // first traversing in y then in x
      {
        if(y <= y2)
        {
          p.x = x;  // origin of the window (original size not the scaled one)
          p.y = y;
          result = runCascadeClassifier ( p,
                                          SUM1_data,
                                          SQSUM1_data,
                                          rectangles_array0,
                                          rectangles_array1,
                                          rectangles_array2,
                                          rectangles_array3,
                                          rectangles_array4,
                                          rectangles_array5,
                                          rectangles_array6,
                                          rectangles_array7,
                                          rectangles_array8,
                                          rectangles_array9,
                                          rectangles_array10,
                                          rectangles_array11, 
                                          stages_array,
                                          stages_thresh_array, 
                                          weights_array0, 
                                          weights_array1,
                                          weights_array2, 
                                          alpha1_array,
                                          alpha2_array,
                                          tree_thresh_array
                                        ); 

          if ( result > 0 )
          {
            MyRect r = {myRound(x*factor), myRound(y*factor), winSize.width, winSize.height}; 
            AllCandidates[*AllCandidates_size]=r;
            *AllCandidates_size=*AllCandidates_size+1;
          }
        }
      } 
    }
  }      
}

int runCascadeClassifier 

( MyPoint pt, 
  int SUM1_data[MAX_HEIGHT][MAX_WIDTH],
  int SQSUM1_data[MAX_HEIGHT][MAX_WIDTH], 
  int rectangles_array0[2913], 
  int rectangles_array1[2913], 
  int rectangles_array2[2913], 
  int rectangles_array3[2913], 
  int rectangles_array4[2913], 
  int rectangles_array5[2913], 
  int rectangles_array6[2913], 
  int rectangles_array7[2913], 
  int rectangles_array8[2913], 
  int rectangles_array9[2913], 
  int rectangles_array10[2913], 
  int rectangles_array11[2913], 
  int stages_array[25],
  int stages_thresh_array[25], 
  int weights_array0[2913],  
  int weights_array1[2913],  
  int weights_array2[2913], 
  int alpha1_array[2913], 
  int alpha2_array[2913],int tree_thresh_array[2913]
) 

{
  int i, j;
  int mean;
  int variance_norm_factor;
  int haar_counter = 0;
  int w_index = 0;
  int r_index = 0;
  int stage_sum=0;

  
  int window0[25][25];
  int window1[25][25];
  int window2[25][25];
  int window3[25][25];
  int window4[25][25];
  int window5[25][25];
  int window6[25][25];
  int window7[25][25];
  int window8[25][25];
  int window9[25][25];
  int window10[25][25];
  int window11[25][25];

 // #pragma HLS array_partition variable=window complete dim=0 
  int coord[12];
  #pragma HLS array_partition variable=coord complete dim=0
  
 // #include "haar_dataRcc_with_partitioning.h"
 // #include "haar_dataRcc.h"
 // # pragma HLS array_partition variable=rectangles_array cyclic factor=12 dim=1
  
  MyRect equRect;

  equRect.x = equRect.y = 0;
  equRect.width = 24;//cascade->orig_window_size.width; // window height
  equRect.height = 24;//cascade->orig_window_size.height; // window width

  /**************************************************************************
   * Image normalization
   * mean is the mean of the pixels in the detection window
   * cascade->pqi[pq_offset] are the squared pixel values (using the squared integral image)
   * inv_window_area is 1 over the total number of pixels in the detection window
   *************************************************************************/
 
  variance_norm_factor =      SQSUM1_data[pt.y][pt.x]
                           -  SQSUM1_data[pt.y][pt.x + equRect.width - 1]
                           -  SQSUM1_data[pt.y + equRect.height - 1][pt.x] 
                           +  SQSUM1_data[pt.y + equRect.height - 1][pt.x + equRect.width - 1];

  mean =                      SUM1_data[pt.y][pt.x]
                           -  SUM1_data[pt.y][pt.x + equRect.width - 1]
                           -  SUM1_data[pt.y + equRect.height - 1][pt.x] 
                           +  SUM1_data[pt.y + equRect.height - 1][pt.x + equRect.width - 1];
      

  variance_norm_factor = (variance_norm_factor*24*24);//cascade->inv_window_area); // var is variance*area so mul by area for consistency in next step
  variance_norm_factor =  variance_norm_factor - mean*mean; // mean is actually mean*area so mean^2 = mean*mean*area*area

  /***********************************************
   * Note:
   * The int_sqrt is softwar integer squre root.
   * More info:
   * http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#standard-functions
   **********************************************/
  if( variance_norm_factor > 0 )
  {
    variance_norm_factor = int_sqrt(variance_norm_factor);  // standard deviation * area
  }
  else
    variance_norm_factor = 1;

  Create_Window:
  for(i=0;i<25;i++)
  {
    for( j=0; j<25 ; j++)
    {
       #pragma HLS pipeline  
       window0[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window1[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window2[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window3[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window4[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window5[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window6[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window7[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window8[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window9[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window10[i][j] = SUM1_data[pt.y + i][pt.x + j];
       window11[i][j] = SUM1_data[pt.y + i][pt.x + j];
    }
  }
    

  MyRect tr0,tr1,tr2;
  
  int filter_no=0 ;
  int r_id;
  int w_id;
  int s;

  rCC1_Stages:
  for ( i =0; i < 25; i++ )
  {
    rCC1_1_Filters_in_every_stage:
    for ( j = 0; j < 211; j++ )
    {
      #pragma HLS pipeline 
      if ( j == 0 )    // to make perfect loop 
      {
        stage_sum = 0;
        s=0;
      } 
      if ( j < stages_array[i] )
      {
        filter_no = haar_counter;
        r_id = r_index;
        w_id = w_index;

        tr0.x = rectangles_array0[filter_no];//[r_id]; 
        tr0.width = rectangles_array2[filter_no];//[r_id + 2]; 
        tr0.y = rectangles_array1[filter_no];//[r_id + 1];
        tr0.height = rectangles_array3[filter_no];//[r_id + 3];
     
        tr1.x = rectangles_array4[filter_no];//[r_id + 4]; 
        tr1.width = rectangles_array6[filter_no];//[r_id + 6];
        tr1.y = rectangles_array5[filter_no];//[r_id + 5];
        tr1.height = rectangles_array7[filter_no];//[r_id + 7];
      
        tr2.x = rectangles_array8[filter_no];//[r_id + 8]; 
        tr2.width = rectangles_array10[filter_no];//[r_id + 10]; 
        tr2.y = rectangles_array9[filter_no];//[r_id + 9];
        tr2.height = rectangles_array11[filter_no];//[r_id + 11];

        if( tr0.width != 0 && tr0.height != 0)
        {
          coord[0] = window0[tr0.y][tr0.x];
          coord[1] = window1[tr0.y][tr0.x+tr0.width];
          coord[2] = window2[tr0.y+tr0.height][tr0.x];
          coord[3] = window3[tr0.y+tr0.height][tr0.x+tr0.width];
        }
        
        if( tr1.width != 0 && tr1.height != 0)
        {                  
          coord[4] = window4[tr1.y][tr1.x];
          coord[5] = window5[tr1.y][tr1.x+tr1.width];
          coord[6] = window6[tr1.y+tr1.height][tr1.x];
          coord[7] = window7[tr1.y+tr1.height][tr1.x+tr1.width];
        }
                   
        if (!(tr2.x ==0 && tr2.width==0 && tr2.y==0 && tr2.height==0 ) && tr2.width!=0 && tr2.height!=0)
        {
          coord[8] = window8[tr2.y][tr2.x];
          coord[9] = window9[tr2.y][tr2.x+tr2.width];
          coord[10] = window10[tr2.y+tr2.height][tr2.x];
          coord[11] = window11[tr2.y+tr2.height][tr2.x+tr2.width];
        }
        else
        {
          coord[8] = 0;
          coord[9] = 0;
          coord[10] = 0;
          coord[11] = 0;
        }
         
        s = evalWeakClassifier1 ( variance_norm_factor, 
                                  coord,
                                  filter_no,
                                  w_id,
                                  weights_array0, 
                                  weights_array1,
                                  weights_array2, 
                                  alpha1_array,
                                  alpha2_array,
                                  tree_thresh_array
                                );
          
        stage_sum = stage_sum + s;
        haar_counter = haar_counter+1;
        w_index = w_index+3;
        r_index = r_index+12;
      
      }
    } /* end of j loop */

      /**************************************************************
       * threshold of the stage. 
       * If the sum is below the threshold, 
       * no faces are detected, 
       * and the search is abandoned at the i-th stage (-i).
       * Otherwise, a face is detected (1)
       **************************************************************/

      /* the number "0.4" is empirically chosen for 5kk73 */
    if( stage_sum < 0.4*stages_thresh_array[i] )
    { 
      return -i; 
    } 
  } /* end of i loop */
 return 1;
}
/****************************************************
 * evalWeakClassifier:
 * the actual computation of a haar filter.
 * More info:
 * http://en.wikipedia.org/wiki/Haar-like_features
 ***************************************************/
  
int evalWeakClassifier1
(
  int variance_norm_factor,
  int coord[12],  
  int filter_no,
  int w_id, 
  int weights_array0[2913],
  int weights_array1[2913],
  int weights_array2[2913], 
  int alpha1_array[2913],
  int alpha2_array[2913],
  int tree_thresh_array[2913]
)
{                                                                                             
  //#include "haar_dataEWC_with_partitioning.h"
  //#include "haar_dataEWC.h"
  //# pragma HLS array_partition variable=weights_array cyclic factor=3 dim=1
  # pragma HLS pipeline 
  int t = tree_thresh_array[filter_no] * variance_norm_factor; 
  
  int sum0 =0;
  int sum1 =0;
  int sum2 =0;
  int final_sum =0;
  int return_value;
	             
  sum0 = (coord[0] - coord[1] - coord[2] + coord[3]) * weights_array0[filter_no];//[w_id] area of 1st filter block (rectangle) multiplied by its weigh
  sum1 = (coord[4] - coord[5] - coord[6] + coord[7]) * weights_array1[filter_no];//[w_id+1];    
  sum2 = (coord[8] - coord[9] - coord[10] + coord[11]) * weights_array2[filter_no];//[w_id+2]; 
  final_sum = sum0+sum1+sum2;
   
  if(final_sum >= t) // if sum >= threshold of the filter
  {
    return_value =  alpha2_array[filter_no];  
  }
  else   
  {
    return_value =  alpha1_array[filter_no];
  }
  
  return return_value ; 

}

/*****************************************************
 * Compute the integral image (and squared integral)
 * Integral image helps quickly sum up an area.
 * More info:
 * http://en.wikipedia.org/wiki/Summed_area_table
 ****************************************************/
void integralImages 
(
  MyImage *src,
  unsigned char IMG1_data[MAX_HEIGHT][MAX_WIDTH],
  MyIntImage *sum,
  int SUM1_data[MAX_HEIGHT][MAX_WIDTH],
  MyIntImage *sqsum, 
  int SQSUM1_data[MAX_HEIGHT][MAX_WIDTH] 
)
{
  int x, y, t, tq;
  unsigned char it;
  int height = src->height;
  int width = src->width;
  int p[60][3],q[60][3];
  // # pragma HLS array_partition variable=p complete dim=0
  // # pragma HLS array_partition variable=q complete dim=0
  // # pragma HLS array_partition variable=SUM1_data block factor=60 dim=2
  // # pragma HLS array_partition variable=SQSUM1_data block factor=60 dim=2
  // # pragma HLS array_partition variable=IMG1_data block factor=60 dim=2
  // # pragma HLS array_partition variable=SUM1_data 
  int y1;            
                    
  IntImagesL1:  
  for( y = 0; y < 60+60 ; y++ )//height/
  {
    //#pragma HLS pipeline
    if ( y < ( height + width ) ) 
    {
    //#pragma HLS pipeline
      for ( x=1 ; x<=60; x++ )
      {
        if ( x >= max ( 1, y-60+1 ) && x <= min ( 60, y ) )
        {
          y1=y-x;
          x=x-1;
          if(x>=1)
          {
            p[x][0] =  SUM1_data[y1][x-1] ;
            q[x][0] =  SQSUM1_data[y1][x-1] ;
          }
          else
          {
            p[x][0] =  0;
            q[x][0] = 0;
          } 
          x=x+1; 
        }
      }
   
      for ( x=1 ; x<=60 ; x++ )
      {
        if ( x >= max ( 1 , y-60+1 ) && x <= min ( 60 , y ) )
        {
          y1=y-x;
          x=x-1;
          if ( x >= 1 && y1 >= 1 )
          {
            p[x][1] =  SUM1_data[y1-1][x-1] ;
            q[x][1] =  SQSUM1_data[y1-1][x-1] ;
          }
          else
          {
            p[x][1] =  0; 
            q[x][1] = 0;
          }
          x=x+1; 
        }
      }
   
      for ( x=1 ; x<=60 ; x++ )
      {
        if ( x >= max ( 1 , y-60+1 ) && x <= min ( 60 , y ) )
        {
          y1 = y - x;
          x  = x - 1;
          if ( y1 >= 1 )
          {
            p[x][2] =  SUM1_data[y1-1][x] ;
            q[x][2] =  SQSUM1_data[y1-1][x] ;
          }
          else
          {
            p[x][2] =  0; 
            q[x][2] = 0;
          }
          x=x+1; 
        }
      }  
                    
      IntImagesL1_1: 
      for ( x=1 ; x<=60 ; x++)
      {
        if ( x >= max ( 1 , y-60+1 ) && x <= min ( 60 , y ) )
        {
          y1 = y-x+1;
          y1 = y1-1;
          x  = x-1;
        
          SUM1_data[y1][x]= p[x][0] + p[x][2] - p[x][1] +IMG1_data[y1][x];
          SQSUM1_data[y1][x] = q[x][0] + q[x][2] - q[x][1] +(IMG1_data[y1][x]*IMG1_data[y1][x]);
        
          x=x+1;
                  	
        }
      }
    }
  }
}


/***********************************************************
 * This function downsample an image using nearest neighbor
 * It is used to build the image pyramid
 **********************************************************/
void nearestNeighbor 
(
  MyInputImage *src,
  unsigned char Data[MAX_HEIGHT][MAX_WIDTH], 
  MyImage *dst,
  unsigned char IMG1_data[MAX_HEIGHT][MAX_WIDTH]
)
{
  int y;
  int j;
  int x;
  int i;
  unsigned char* t;
  unsigned char* p;
  int w1 = src->width;
  int h1 = src->height;
  int w2 = dst->width;
  int h2 = dst->height;

  int rat = 0;

  int x_ratio = (int)((w1<<16)/w2) +1; 
  int y_ratio = (int)((h1<<16)/h2) +1;


  nearestNeighborL1:  
  for ( i = 0 ; i < 60 ; i++ )
  { 
    if ( i < h2 )
    {
      nearestNeighborL1_1:  
      for (j=0;j<60;j++)
      {
        #pragma HLS pipeline
        if ( j < w2 ) 
        {
          IMG1_data[i][j] =  Data[(i*y_ratio)>>16][(j*x_ratio)>>16];
        }
      }
    }
  }
}
/***********************************************
 * Note:
 * The int_sqrt is softwar integer squre root.
 * GPU has hardware for floating squre root (sqrtf).
 * In GPU, it is wise to convert an int variable
 * into floating point, and use HW sqrtf function.
 * More info:
 * http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#standard-functions
 **********************************************/
/*****************************************************
 * The int_sqrt is only used in runCascadeClassifier
 * If you want to replace int_sqrt with HW sqrtf in GPU,
 * simple look into the runCascadeClassifier function.
 *****************************************************/
unsigned int int_sqrt 
( 
  unsigned int value
)
{
  int i;
  unsigned int a = 0, b = 0, c = 0;
  for ( i = 0 ; i < (32 >> 1) ; i++ )
  {
    c<<= 2;
    #define UPPERBITS(value) (value>>30)
    c += UPPERBITS(value);
    #undef UPPERBITS
    value <<= 2;
    a <<= 1;
    b = (a<<1) | 1;
    if ( c >= b )
    {
      c -= b;
      a++;
    }
  }
  return a;
}

int max
(
  int a,
   int b
)
{
 if ( a > b )
   return a;
 else 
   return b;
}

int min
(
  int a,
  int b
)
{
  if ( a < b )
    return a;
  else 
    return b;
}

