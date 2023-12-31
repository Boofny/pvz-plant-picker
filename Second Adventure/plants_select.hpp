#pragma once

#include "plants_parser.hpp"
#include "crazy_dave.hpp"
#include <algorithm>
#include <time.h>

/*
FEATURES TO ADD:

- Make crazy_dave.hpp (for dealing with plants that Crazy Dave has)
- Lower the chances for the program to choose night time, pool and rooftop only plants 
*/

void select() {
    srand(time(NULL));

    std::vector<std::string> plants = parse_plants();
    std::vector<std::string> crazy_dave_plants = crazy_dave();
    std::vector<std::string> random_plants;
    std::vector<int> lane_index = {1, 2, 3, 4, 5};

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int seed_slot = 7;

    for(int i = 0; i < seed_slot; i++) {
        int random_number = rand() % plants.size();
        std::string selected_plant = plants[random_number];

        bool is_duplicate = false;
        for (const std::string& existing_plant : random_plants) {
            if (existing_plant == selected_plant) {
                is_duplicate = true;
                break;
            }
        }

        if (!is_duplicate) {
            random_plants.push_back(selected_plant);
        }

    }

    Sleep(1000);

    for(int i = 0; i < seed_slot; i++) {
        SetConsoleTextAttribute(h, i + 1);
        std::cout << "SELECT PLANT NUMBER " << i + 1 << ": ";
        Sleep(1000);
        std::cout << random_plants[i] << '\n';
        Sleep(500);
    }

    Sleep(1000);
    std::cout << '\n';

    SetConsoleTextAttribute(h, 7);
    std::cout << "PRESS ENTER TO CONTINUE.\n";
    if (GetAsyncKeyState(VK_RETURN) & 0x8001) {}
    std::cout << '\n';

    int action_performed {0};
    while (true) {
        int generator_plants = rand() % 7;
        int generator_lanes  = rand() % 5 + 1;
        if ((GetAsyncKeyState(VK_RETURN) & 0x8001) && !(action_performed)) {
            std::cout << "PUT PLANT " << random_plants[generator_plants] << " ON LANE " << generator_lanes << '\n';
            action_performed = 1;
        } else if (!(GetAsyncKeyState(VK_RETURN)) & 0x8001) {
            action_performed = 0;
        }
    }

    SetConsoleTextAttribute(h, 7);
}