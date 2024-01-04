#pragma once
#include "plants_parser.hpp"

std::vector<std::string> crazy_dave() {
    std::ifstream dave("crazy_dave_plants.txt");
    std::vector<std::string> crazyDavePlants;
    std::string plant;

    if (!dave.is_open()) std::cout << "Trouble opening crazy_dave_plants.txt!\n";
    else {
        while (dave >> plant) {
            crazyDavePlants.push_back(plant);
        }

        dave.close();
    }

    return crazyDavePlants;
}