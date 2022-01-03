#include <algorithm>
#include <boost/program_options.hpp>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

#include "numberplate_exprs.hpp"
namespace bpo = boost::program_options;

int main(int argc, char **argv) {
    bpo::options_description opt("option");
    opt.add_options()("help,h", "show this help")("nums,n", bpo::value<std::vector<int>>()->multitoken(),
                                                  "space separated numberplate,required")(
        "dest,d", bpo::value<int>()->default_value(10), "destination value")(
        "all_permutation,p", "try all possible permutation")("only-num,o", "output only the number of solutions found");

    bpo::variables_map varmap;
    bpo::store(bpo::parse_command_line(argc, argv, opt), varmap);
    bpo::notify(varmap);
    if (varmap.count("help")) {
        std::cout << opt << std::endl;
        std::exit(EXIT_SUCCESS);
    }
    if (!varmap.count("nums")) {
        std::cerr << "error: too few arguments" << std::endl;
        std::cerr << opt << std::endl;
        std::exit(EXIT_FAILURE);
    }
    auto np = varmap["nums"].as<std::vector<int>>();
    if (np.size() != 4) {
        std::cerr << "error: numberplate must be 4 digits" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    auto destination = varmap["dest"].as<int>();
    std::set<std::string> ok_pretties;
    if (!varmap.count("all_permutation")) {
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
    if (!varmap.count("only-num")) {
        for (const auto ok_pretty : ok_pretties) {
            std::cout << ok_pretty << std::endl;
        }
    }
    return 0;
}
