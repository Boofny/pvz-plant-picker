#pragma once

/*
GENERATOR FOR LEVEL 1 - 2

This was made because level 1 - 2 has two plants and three lanes.
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>

std::vector<std::string> available_plants = {
    "Peashooter",
    "Sunflower"
};

void randomizer_level2() {
    srand(time(NULL));

    int action_performed {0};
    while (true) {
        int generator_plants = rand() % 2;
        int generator_lanes  = rand() % 3 + 1;
        if ((GetAsyncKeyState(VK_RETURN) & 0x8001) && !(action_performed)) {
            std::cout << "PUT PLANT " << available_plants[generator_plants] << " ON LANE " << generator_lanes << '\n';
            action_performed = 1;
        } else if (!(GetAsyncKeyState(VK_RETURN)) & 0x8001) {
            action_performed = 0;
        }
    }
}