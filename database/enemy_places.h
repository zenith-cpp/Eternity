#pragma once
#include <vector>
#include "enemies.h"
#include "items.h"
#include "weapons.h"

class Character;
class EnemyPlace {
public:
    std::string name;
    std::vector<Character> possible_enemies;
    std::vector<Weapon> possible_loots_weapon;
    std::vector<Item> possible_loots_item;
    int place_difficulty;
    EnemyPlace(std::string name, std::vector<Character> possible_enemies, std::vector<Weapon> possible_loots_weapon, std::vector<Item> possible_loots_item, int place_difficulty);
    void go_in(Character& player);
};

extern EnemyPlace nerar_dummy_test;