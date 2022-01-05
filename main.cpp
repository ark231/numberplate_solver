#include <iostream>
#include <string>

#include "numberplate_solver.hpp"
int main(int argc, char **argv) {
    if (argc < 5) {
        std::cerr << "too few args" << std::endl;
        return 1;
    }
    int A = std::atoi(argv[1]);
    int B = std::atoi(argv[2]);
    int C = std::atoi(argv[3]);
    int D = std::atoi(argv[4]);
    auto solutions = numberplate::solve_numberplate(A, B, C, D);
    for (const auto &solution : solutions) {
        std::cout << solution << std::endl;
    }
    return 0;
}
