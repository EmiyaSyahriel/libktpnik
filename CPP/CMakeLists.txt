cmake_minimum_required(VERSION 3.0)

project(ktpnik_cpp)

add_library(ktpnik SHARED ktpnik/ktpnik.cpp)
add_library(ktpnik_s STATIC ktpnik/ktpnik.cpp)
target_include_directories(ktpnik PUBLIC "include")
target_include_directories(ktpnik_s PUBLIC "include")

option(KTPNIK_COMPILE_SAMPLE "Compile KtpNik Sample" OFF)

if(KTPNIK_COMPILE_SAMPLE)
	add_executable(ktpnik_sample sample/sample.cpp)
	target_link_libraries(ktpnik_sample PRIVATE ktpnik_s)
endif()