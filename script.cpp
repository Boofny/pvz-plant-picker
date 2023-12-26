#include <iostream>
#include "plants_parser.hpp"
#include "plants_select.hpp"

int main() {
    std::vector<std::string> plants = parse_plants();

    select(plants);
    return 0;
}