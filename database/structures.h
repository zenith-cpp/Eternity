#pragma once
#include <vector>
#include "npcs.h"

class Structure {
public:
    std::string name;
    std::vector<NonPlayableCharacter> list_of_npcs;

    Structure(std::string name, std::vector<NonPlayableCharacter> list_of_npcs);
    Structure();
};


// Here are the buildings available
//? Buildings of Nerar
extern Structure nerar_arys_shop;
extern Structure nerar_frontguard_office;
extern Structure nerar_blacksmith;
extern Structure nerar_glarys_shop;