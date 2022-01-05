cmake_minimum_required(VERSION 3.16)

project(numberplate_solver LANGUAGES CXX )
set(CMAKE_CXX_STANDARD 17)

add_library(numberplate_exprs STATIC
    numberplate_exprs.cpp
    )
    add_library(numberplate_solver STATIC
    numberplate_solver.cpp
    )
target_link_libraries(numberplate_solver PUBLIC numberplate_exprs)
if(NOT ANDROID)
add_executable(solve_numberplate
    main.cpp
    )
target_link_libraries(solve_numberplate PUBLIC numberplate_solver)
endif()
