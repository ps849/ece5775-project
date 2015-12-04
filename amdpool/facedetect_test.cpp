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
#include "facedetect.h"
#include "timer.h"

#define INPUT_FILENAME "Face2.pgm"
#define OUTPUT_FILENAME "Output.pgm"

using namespace std;



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
//------------------------------------------------------------
  #include "image_data3.h" // Include image file here
//------------------------------------------------------------
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
 
  // Timer
  Timer timer("Facedetect software"); 

//--------------------------------------------------------------------------------------------	 
  // HLS streams for communicating with the detectobjects block
  hls::stream<bit32_t> detectobject_in;
  hls::stream<bit32_t> detectobject_out;
 
  timer.start();

 // send image pixels to dut
  bit32_t input;

  for (int j = 0; j < 60; j++)
  {
  	for (int k = 0; k < 15; k++ )
  	{    // packing four pixels together
  	     input.range(7,0) = Data[j][4*k];
             input.range(15,8)= Data[j][4*k+1];
             input.range(23,16)= Data[j][4*k+2];
             input.range(31,24)= Data[j][4*k+3];

             // sending four pixel values at a time 	
  	     detectobject_in.write( input );
  	}
  }
  
  // execute detect objects
  dut (detectobject_in, detectobject_out);
  
  // read the output
  
  // Read result
      res_size = detectobject_out.read();
      
      for ( i =0; i < *result_size; i++ )
  {
       result[i].x = detectobject_out.read();
       result[i].y = detectobject_out.read();
       result[i].width = detectobject_out.read();
       result[i].height = detectobject_out.read();
       
  }
  timer.stop(); 
                  
 //---------------------------------------------------------------------------------------------------------- 
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
