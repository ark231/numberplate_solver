cmake_minimum_required(VERSION 3.16)

project(numberplate_solver LANGUAGES CXX )
set(CMAKE_CXX_STANDARD 17)

add_library(numberplate_exprs STATIC
    numberplate_exprs.cpp
    )
if(ANDROID)
    add_library(numberplate_solver STATIC
    numberplate_solver.cpp
    )
else()
add_executable(numberplate_solver
    numberplate_solver.cpp
    )
endif()
target_link_libraries(numberplate_solver PUBLIC numberplate_exprs)
