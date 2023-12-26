#include <iostream>
#include "plants_parser.hpp"

int main() {
    std::vector<std::string> plants = parse_plants();

    for(int i = 0; i < plants.size(); i++) {
        std::cout << "PLANT NAME: " << plants[i] << '\n';
    }
    return 0;
}