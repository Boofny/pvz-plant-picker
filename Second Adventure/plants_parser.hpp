#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <conio.h>

std::vector<std::string> parse_plants() {
    std::ifstream plants_input("plants.txt");
    std::vector<std::string> plants;
    std::string element;

    if (!plants_input.is_open()) std::cout << "Error! Could not open file.\n";
    else {
    
        while (plants_input >> element) {
            plants.push_back(element);
        }

        plants_input.close();

    }
    return plants;
}