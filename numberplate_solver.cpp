#include "numberplate_solver.hpp"

#include <algorithm>
#include <set>
#include <string>
#include <vector>

#include "numberplate_exprs.hpp"
namespace numberplate {
std::set<std::string> solve_numberplate(int A, int B, int C, int D, int destination, bool all_permutation,
                                        bool oneliner) {
    std::vector<int> np = {A, B, C, D};
    std::set<std::string> ok_pretties;
    if (!all_permutation) {
        for (const auto expr : numberplate::EXPRS) {
            if (expr(np[0], np[1], np[2], np[3]) == destination) {
                if (oneliner) {
                    ok_pretties.insert(expr.pretty_oneline(np[0], np[1], np[2], np[3]));
                } else {
                    ok_pretties.insert(expr.pretty(np[0], np[1], np[2], np[3]));
                }
            }
        }
    } else {
        std::vector<int> idxs_replaced = {0, 1, 2, 3};
        do {
            std::vector<int> np_replaced(4, 0);
            for (auto i = 0; i < 4; i++) {
                np_replaced[i] = np[idxs_replaced[i]];
            }
            for (const auto expr : numberplate::EXPRS) {
                if (expr(np_replaced[0], np_replaced[1], np_replaced[2], np_replaced[3]) == destination) {
                    if (oneliner) {
                        ok_pretties.insert(
                            expr.pretty_oneline(np_replaced[0], np_replaced[1], np_replaced[2], np_replaced[3]));
                    } else {
                        ok_pretties.insert(expr.pretty(np_replaced[0], np_replaced[1], np_replaced[2], np_replaced[3]));
                    }
                }
            }
        } while (std::next_permutation(idxs_replaced.begin(), idxs_replaced.end()));
    }
    return ok_pretties;
}
}  // namespace numberplate
