cmake_minimum_required(VERSION 3.31)
project(ik_solver VERSION 0.2.0)

set(SOURCE main.cpp window.cpp chain.cpp bone.cpp)
set(HEADERS window.h chain.h bone.h)

find_package(SDL2 REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main Eigen3::Eigen)