#==========================================================================
# Makefile
#==========================================================================
# @brief: A makefile the compiles and runs the facedetect program
#
# @desc: 1. "make" or "make sw" runs software execution by default
#        2. "make clean" cleans up the directory


HEADERS := image.h haar.h stdio-wrapper.h


# Extract Vivado HLS include path
VHLS_PATH := $(dir $(shell which vivado_hls))/..
VHLS_INC ?= ${VHLS_PATH}/include

CFLAGS = -g -I${VHLS_INC}



sw: facedetect.cpp facedetect_test.cpp image.cpp stdio-wrapper.cpp rectangles.cpp
	@echo "Compiling & executing facedetect software program on amdpool..."
	g++ ${CFLAGS} facedetect.cpp facedetect_test.cpp haar.cpp  image.cpp stdio-wrapper.cpp rectangles.cpp -o facedetect-x86
	./facedetect-x86


clean:
	rm -rf facedetect-x86 Output.pgm *.prj *.log
