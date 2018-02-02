cmake_minimum_required(VERSION 3.8)
project(edu_csci2421)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES hw1/main.cpp hw1/guess.cpp hw1/guess.h)
add_executable(edu_csci2421 ${SOURCE_FILES})