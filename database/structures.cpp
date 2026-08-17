#include "structures.h"
#include "utils/listof_npcs.h"
#include <iostream>

Structure::Structure(std::string name, std::vector<NonPlayableCharacter> list_of_npcs) {
    this->name = name;
    this->list_of_npcs = list_of_npcs;
}

Structure::Structure() : name(""), list_of_npcs{} {} // default constructor
/*
extern Structure nerar_arys_shop;
extern Structure nerar_frontguard_office;
extern Structure nerar_blacksmith;
extern Structure nerar_glarys_shop;
*/
Structure nerar_arys_shop("Ary's Shop", list_of_npcs_nerar_arys_shop);
Structure nerar_frontguard_office("Front Guard's Office", std::vector<NonPlayableCharacter>{});
Structure nerar_blacksmith("Blacksmith", list_of_npcs_nerar_blacksmith);
Structure nerar_glarys_shop("Glary's Shop", list_of_npcs_nerar_glarys_shop);