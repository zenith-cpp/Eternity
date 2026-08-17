#pragma once
#include <vector>
#include "npcs.h"
#include "structures.h"

class Place {
public:
    std::string name;
    std::vector<NonPlayableCharacter> list_of_npcs;
    std::vector<Structure> list_of_structures;

    Place(std::string name, std::vector<NonPlayableCharacter> list_of_npcs, std::vector<Structure> list_of_structures);
    Place();
};

extern Place nerar;