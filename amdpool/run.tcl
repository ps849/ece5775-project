#=============================================================================
# run.tcl
#=============================================================================
# @brief: A Tcl script for synthesizing the detectObjects design.

# Open/reset the project
open_project hls.prj -reset

# Top function of the design is "dut"
set_top dut


# Add design and testbench files
add_files haar.cpp
add_files facedetect.cpp

add_files -tb facedetect_test.cpp
add_files -tb stdio-wrapper.cpp
add_files -tb image.cpp
add_files -tb rectangles.cpp

open_solution solution1
 
# Use Zynq device
set_part xc7z020clg484-1
config_rtl -reset state

# Simulate the C++ design
 csim_design
# Synthesize the design
#csynth_design
# Co-simulate the design
#cosim_design

exit
