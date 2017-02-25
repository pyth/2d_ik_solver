cmake_minimum_required(VERSION 2.8.4)
project(ik_solver)

set(CMAKE_PREFIX_PATH "" CACHE PATH "3rd party libraries and headers")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories(${CMAKE_PREFIX_PATH})
link_directories(${CMAKE_PREFIX_PATH})
if(EXISTS /usr/include/eigen3)
	include_directories(/usr/include/eigen3)
endif()

add_subdirectory(src)
