cmake_minimum_required(VERSION 3.23)
project(BMPInformer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(BMPInformer main.cpp include/bmp.h include/Bitmap.h)
