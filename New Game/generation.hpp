#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <windows.h>

std::vector<std::string> parse_plants() {
    std::ifstream plants("plants.txt");
    std::vector<std::string> parsed_plants;
    std::string plant;

    if (!plants.is_open()) std::cout << "Trouble opening plants.txt!\n";
    else {
        while (plants >> plant) {
            parsed_plants.push_back(plant);
        }
    }

    return parsed_plants;
}