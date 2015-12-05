#==========================================================================
# Makefile
#==========================================================================
# @brief: A makefile the compiles and runs the facedetect program
#
# @desc: 1. "make" or "make sw" runs software execution by default
#        2. "make fpga" invokes the detectObjects HW accelerator
#        3. "make clean" cleans up the directory


HEADERS := image.h haar.h stdio-wrapper.h

INC_PATH=/usr/include/vivado_hls/2015.2
CFLAGS = -I${INC_PATH}



sw: facedetect.cpp facedetect_test.cpp image.cpp stdio-wrapper.cpp rectangles.cpp
	@echo "Compiling & executing facedetect software program on ARM ..."
	g++ ${CFLAGS} facedetect.cpp facedetect_test.cpp haar.cpp  image.cpp stdio-wrapper.cpp rectangles.cpp -o facedetect-arm
	./facedetect-arm

fpga: host.cpp image.cpp stdio-wrapper.cpp rectangles.cpp
	@echo "Compiling host program & running detect accelerator ..."
	g++ ${CFLAGS} host.cpp image.cpp stdio-wrapper.cpp rectangles.cpp -o detect-fpga
	./detect-fpga

clean:
	rm -f detect-fpga facedetect-arm Output.pgm
