#pragma once

#include "plants_parser.hpp"
#include <time.h>

void select() {
    srand(time(NULL));

    std::vector<std::string> plants = parse_plants();

    std::vector<std::string> random_plants;

    for(int i = 0; i < 7; i++) {
        int random_number = rand() % 49 + 1;
        random_plants.push_back(plants[random_number]);
    }

    for(int i = 0; i < 7; i++) {
        std::cout << "SELECT PLANT NUMBER " << i + 1 << ": " << random_plants[i] << '\n';
    }
}