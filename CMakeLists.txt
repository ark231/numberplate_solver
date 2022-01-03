cmake_minimum_required(VERSION 3.16)

project(numberplate_solver LANGUAGES CXX )
set(CMAKE_CXX_STANDARD 17)

add_library(numberplate_exprs STATIC
    numberplate_exprs.cpp
    )
add_executable(numberplate_solver
    numberplate_solver.cpp
    )
find_package(Boost 1.71 COMPONENTS program_options REQUIRED )
target_include_directories(numberplate_solver PUBLIC ${Boost_INCLUDE_DIR} )
target_link_libraries(numberplate_solver PUBLIC ${Boost_LIBRARIES} )
target_link_libraries(numberplate_solver PUBLIC numberplate_exprs)
