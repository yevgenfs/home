
#add_executable(small_project main.c)

cmake_minimum_required(VERSION 2.8.9)
project(small_project)
set(CMAKE_BUILD_TYPE Release)

#Bring the headers, such as Student.h into the project
include_directories(header)
  
file(GLOB SOURCES  "C:/Users/yevhen.surkov/Documents/home/source/*.c")

add_library(small_project_test SHARED ${SOURCES})

install(TARGETS small_project_test DESTINATION C:/Users/yevhen.surkov/Documents/home)
#add_executable(hello "C:/Users/yevhen.surkov/Documents/home/source/main.c")