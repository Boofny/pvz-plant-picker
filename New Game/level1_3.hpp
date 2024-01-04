#pragma once

/*
GENERATOR FOR LEVEL 1 - 3

This was made because level 1 - 3 has three plants and (still) three lanes.
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>

std::vector<std::string> plants_for_level3 = {
    "Peashooter",
    "Sunflower",
    "Cherry-Bomb"
};

void randomizer_level3() {
    srand(time(NULL));

    int action_performed {0};
    while (true) {
        int generator_plants = rand() % 3;
        int generator_lanes  = rand() % 3 + 1;
        if ((GetAsyncKeyState(VK_RETURN) & 0x8001) && !(action_performed)) {
            std::cout << "PUT PLANT " << plants_for_level3[generator_plants] << " ON LANE " << generator_lanes << '\n';
            action_performed = 1;
        } else if (!(GetAsyncKeyState(VK_RETURN)) & 0x8001) {
            action_performed = 0;
        }
    }
}