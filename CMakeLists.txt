
#add_executable(small_project main.c)

cmake_minimum_required(VERSION 2.8.9)
project(small_project)
 
#Bring the headers, such as Student.h into the project
include_directories(header)
  
file(GLOB SOURCES "source/*.c")
 
add_executable(hello "C:/Users/yevhen.surkov/Documents/home/source/main.c")