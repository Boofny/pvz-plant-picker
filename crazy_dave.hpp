#pragma once
#include "plants_parser.hpp"

std::vector<std::string> crazy_dave() {
    std::vector<std::string> crazyDavePlants;
    std::string plant;
    for(int i = 1; i <= 3; i++) {
        std::cout << "Enter the " << i + 1 << " Crazy Dave plant!\n";
        std::cin >> plant;
        crazyDavePlants.push_back(plant);
    }

    return crazyDavePlants;
}