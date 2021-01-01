# CMakeList.txt : CMake project for CM_HangMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/WordList.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
# Add source to this project's executable.
add_executable (CM_HangMan "CM_HangMan.cpp" "CM_HangMan.h" "Game.cpp")

# TODO: Add tests and install targets if needed.
