#pragma once

#include "plants_parser.hpp"

void select(std::vector<std::string> plants) {
    plants = parse_plants();

    for(int i = 0; i < plants.size(); i++) {
        std::cout << plants[i] << '\n';
    }
}