cmake_minimum_required(VERSION 3.0)

project(libktpnik C)
option(BUILD_STATIC_LIB "Build static library" OFF)
option(BUILD_SAMPLE_EXE "Build sample executablle" OFF)

set(ktpnik_src libsrc/ktpnik.c)
set(ktpnik_inc include)

if(BUILD_STATIC_LIB)
	message("Building static library")	
	add_library(ktpnik STATIC ${ktpnik_src})
	target_compile_definitions(ktpnik PRIVATE KTPNIK_STATIC_LIB KTPNIK_BUILD_LIB)
else()
	message("Building shared library")
	add_library(ktpnik SHARED ${ktpnik_src})
	target_compile_definitions(ktpnik PRIVATE KTPNIK_SHARED_LIB KTPNIK_BUILD_LIB)
endif()

target_include_directories(ktpnik PUBLIC ${ktpnik_inc})

if(WIN32)
	set_target_properties(ktpnik PROPERTIES PREFIX "lib")
endif()

if(BUILD_SAMPLE_EXE)
	message("Building sample executable")
	add_executable(ktpnik_test sample/sample.c)
	target_include_directories(ktpnik_test PRIVATE ${ktpnik_inc})
	target_link_libraries(ktpnik_test PRIVATE ktpnik)
	if(ANDROID)
	set_target_properties(ktpnik_test PROPERTIES SUFFIX ".elf")
	endif()
endif()