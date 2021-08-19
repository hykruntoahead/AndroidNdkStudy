cmake_minimum_required(VERSION 3.5.1)
project(dynamicRegister)

set(CMAKE_CXX_STANDARD 11)
 
#add_library(register SHARED library.cpp library.h )
 
add_library(drLib SHARED JniTest.h JniTest.c)
 
 