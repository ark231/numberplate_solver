#ifndef NUMBERPLATE_SOLVER
#define NUMBERPLATE_SOLVER
#include <set>
#include <string>
namespace numberplate {
std::set<std::string> solve_numberplate(int A, int B, int C, int D, int destination = 10, bool all_permutation = false,
                                        bool oneliner = false);
}
#endif
