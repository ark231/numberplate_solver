#include <algorithm>
#include <any>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "numberplate_exprs.hpp"

int solve_numberplate(int A, int B, int C, int D, int destination = 10, bool all_permutation = false,
                      bool only_num = false) {
    std::vector<int> np = {A, B, C, D};
    std::set<std::string> ok_pretties;
    if (!all_permutation) {
        for (const auto expr : numberplate::EXPRS) {
            if (expr(np[0], np[1], np[2], np[3]) == destination) {
                ok_pretties.insert(expr.pretty(np[0], np[1], np[2], np[3]));
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
                    ok_pretties.insert(expr.pretty(np_replaced[0], np_replaced[1], np_replaced[2], np_replaced[3]));
                }
            }
        } while (std::next_permutation(idxs_replaced.begin(), idxs_replaced.end()));
    }
    std::cout << ok_pretties.size() << " solutions found" << std::endl;
    if (!only_num) {
        for (const auto ok_pretty : ok_pretties) {
            std::cout << ok_pretty << std::endl;
        }
    }
    return 0;
}
