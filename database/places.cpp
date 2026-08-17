#include "places.h"

Place::Place(std::string name, std::vector<NonPlayableCharacter> list_of_npcs, std::vector<Structure> list_of_structures) {
    this->name = name;
    this->list_of_npcs = list_of_npcs;
    this->list_of_structures = list_of_structures;
}

Place::Place() : name(""), list_of_npcs{}, list_of_structures{} {} // default constructor

Place nerar("Nerar", std::vector<NonPlayableCharacter>{}, std::vector<Structure>{});