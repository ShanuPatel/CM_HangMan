# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CM_HangMan")

# Include sub-projects.
add_subdirectory ("glfw")
add_subdirectory ("CM_HangMan")

target_include_directories(CM_HangMan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)