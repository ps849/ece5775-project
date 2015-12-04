//=========================================================================
// facedetect.h
//=========================================================================
 
#ifndef FACEDETECT_H
#define FACEDETECT_H

#include <hls_stream.h>

#include "typedefs.h"




// Top function for synthesis
void dut (
    hls::stream<bit32_t> &strm_in,
    hls::stream<bit32_t> &strm_out
);



#endif
