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

void randomizer() {
    srand(time(NULL));
    std::vector<std::string> plants = parse_plants();
    
    if (plants.size() <= 6) {
        int action_performed {0};
        while (true) {
            int generator_plants = rand() % plants.size();
            int generator_lanes  = rand() % 5 + 1;
            if ((GetAsyncKeyState(VK_RETURN) & 0x8001) && !(action_performed)) {
                std::cout << "PUT PLANT " << plants[generator_plants] << " ON LANE " << generator_lanes << '\n';
                action_performed = 1;
            } else if (!(GetAsyncKeyState(VK_RETURN)) & 0x8001) {
                action_performed = 0;
            }
        }   
    } else {
        //For levels after getting 7 or more plants
    }
}