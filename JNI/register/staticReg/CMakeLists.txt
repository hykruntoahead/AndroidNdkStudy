cmake_minimum_required(VERSION 3.5.1)
project(staticRegister)

set(CMAKE_CXX_STANDARD 11)
 
#add_library(register SHARED library.cpp library.h )
 
add_library(firstLib SHARED StaticRegiester.h StaticRegiester.c)
 
 