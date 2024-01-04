#include <iostream>
#include "level1_2.hpp"
#include "level1_3.hpp"
#include "generation.hpp"

int main() {
    int level;
    std::cout << "On what level are you on lol?\n";
    std::cin >> level;

    switch (level) {
        case 2:
            randomizer_level2();
            break;
        case 3:
            randomizer_level3();
        default:
            randomizer();
    }
    return 0;
}