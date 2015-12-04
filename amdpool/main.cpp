#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "stdio-wrapper.h"
#include "haar.h"
#include "image.h"

#define INPUT_FILENAME "Face2.pgm"
#define OUTPUT_FILENAME "Output.pgm"

using namespace std;

void detectObjects( unsigned char Data[MAX_HEIGHT][MAX_WIDTH], MyRect _result[500], int *result_size);

int main ( int argc, char *argv[] ) 
{
  
  int flag;
  int in_flag , in_width , in_height , in_maxgrey;
  int ret_val=1;
	
  int mode = 1;
  int i;
  float scaleFactor = 1.2;  // image will be scaled by 1.2 each time
  int minNeighbours = 1;
        
  printf ("-- entering main function --\r\n");
  printf ("-- loading image --\r\n");
         
  MyInputImage imageObj;
  MyInputImage *image = &imageObj;

  #include "image_data3.h" // image file
 
  image->flag =in_flag;
  image->width = in_width;
  image->height = in_height;
  image->maxgrey = in_maxgrey;        

  printf ("-- loading image [DONE] --\r\n");

  if ( flag == -1 )
  {
    printf( "Unable to open input image\n");
    return 1;
  }

  MySize minSize = {20, 20}; // window size even after scaling should be greater than this
  MySize maxSize = {0, 0};

  // Arguments to be passed to DUT	
  MyRect result[500];
  int res_size=0;
  int *result_size = &res_size;
  
  printf ("-- detecting faces --\r\n");
  printf ("result_size[Begin]= %d", *result_size);
	 
  detectObjects (
                  Data,
                  result, 
                  result_size
                ); // Instantiating the DUT
  
  printf("\nresult_size[Done]= %d", *result_size);

  for( int i=0 ; i < *result_size ; i++ )
  {
    printf("\n [Test Bench (main) ] detected rects: %d %d %d %d",result[i].x,result[i].y,result[i].width,result[i].height);
    /*if ( result[i].x == 12 && result[i].y == 14 && result[i].width == 35 && result[i].height == 35 ) // Checking with Golden Reference Value
    {
       printf("\n[PASSED]: Face Detected at correct Position\n");
       ret_val=0;
    }*/
  }
  if ( *result_size > 0 )
  {
    ret_val = 0;
  }
  
  for(i = 0; i < *result_size ; i++ )
  {
    MyRect r = result[i];
    drawRectangle(image,Data, r);
  }
	
  printf("\n-- saving output image [Start] --\r\n"); 
  flag = writePgm((char *)OUTPUT_FILENAME, image,Data); 
  printf("\n-- saving output image [Done] --\r\n");

  return ret_val;        
}
