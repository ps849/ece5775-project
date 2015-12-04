#include <stdio.h>
#include <stdlib.h>
#include "haar.h"
#include <iostream>
#include "facedetect.h"

using namespace std;

void detectObjects( unsigned char Data[MAX_HEIGHT][MAX_WIDTH], MyRect _result[500], int *result_size);

void dut (
            hls::stream<bit32_t> &strm_in,
            hls::stream<bit32_t> &strm_out
)

{     
    // ------------------------------------------------------
  // Input processing
  // ------------------------------------------------------
  // Read 60x60 pixels over an 8-bit FIFO channel
  
  bit32_t input;    
  MyRect result[500];
  int res_size=0;
  int *result_size = &res_size;
  unsigned char Data[60][60];
  
 
      
      	for ( int j = 0; j < 60; j++ )
     	{
     		 for (int k = 0; k < 15; k++)
     		{
                  	input = strm_in.read();
     			Data[j][4*k] = input.range(7,0);
                        Data[j][4*k+1] = input.range(15,8);
                        Data[j][4*k+2] = input.range(23,16);
                        Data[j][4*k+3] = input.range(31,24);
     			
     		}
     	}
	
     
  
  // ------------------------------------------------------
  // Call detect objects 
  // ------------------------------------------------------
   
   detectObjects ( Data, result, result_size );
  
  // ------------------------------------------------------
  // Output processing
  // ------------------------------------------------------
  
  strm_out.write( *result_size   );
  // Write out the all the attributes of result, 8 bits at a time 
  
  for ( int i =0; i < *result_size; i++ )
  {
       strm_out.write( result[i].x      );    
                                           
       strm_out.write( result[i].y      );  
  
       strm_out.write( result[i].width  );
  
       strm_out.write( result[i].height );
  }		
  
  // Write out the result_size value 8 bits at a time
  
  	
}

