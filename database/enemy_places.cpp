#include "enemy_places.h"
#include "utils/classes_and_functions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

EnemyPlace::EnemyPlace(std::string name, std::vector<Character> possible_enemies, std::vector<Weapon> possible_loots_weapon, std::vector<Item> possible_loots_item, int place_difficulty) : 
    name(name), 
    possible_enemies(possible_enemies),
    possible_loots_weapon(possible_loots_weapon), 
    possible_loots_item(possible_loots_item),
    place_difficulty(place_difficulty) {};
void EnemyPlace::go_in(Character& player) {
    srand(time(NULL));
    c();
    pstory(gray + "* You entered " + this->name + "*");
    int o;
    int enemy_encounter_chance = 20 + (this->place_difficulty * 10); // so 30 is the minimum
    int loot_encounter_chance = 10 + (this->place_difficulty * 10);
    int weapon_encounter_chance = 7 + (this->place_difficulty * 10);
    do{
        std::cout << "1. Go forward." << std::endl;
        std::cout << "2. Return to the exit." << std::endl;
        std::cin >> o;
        if(o == 1) {
            c();
            int chance = rand() % 100; // to avoid generating new numbers everytime
            if(chance <= enemy_encounter_chance) { //! When you encounter an enemy
                int random_enemy_linenum = rand() % this->possible_enemies.size();
                Character enc_enemy = this->possible_enemies[random_enemy_linenum];
                combat(player, enc_enemy);
            } else if(chance <= enemy_encounter_chance + loot_encounter_chance) { //! When you encounter a loot but dont encounter an enemy
                int item_choice;
                int random_loot_linenum1 = rand() % this->possible_loots_item.size();
                int random_loot_linenum2 = rand() % this->possible_loots_item.size();
                int random_loot_linenum3 = rand() % this->possible_loots_item.size();
                bool looted_loot1 = false;
                bool looted_loot2 = false;
                bool looted_loot3 = false;
                while(item_choice != 5) {
                    pstory(cyan + "You Found:");
                    if(chance <= weapon_encounter_chance) {
                        int random_weapon_linenum = rand() % this->possible_loots_weapon.size();
                        int take_weaponYN;
                        pstory("A " + this->possible_loots_weapon[random_weapon_linenum].name + "! Take?");
                        pstory("1. Yes");
                        pstory("2. No");
                        std::cin >> take_weaponYN;
                        if(take_weaponYN == 1) player.change_weapon(this->possible_loots_weapon[random_weapon_linenum]);
                    }

                    //! 1st loot
                    if(!looted_loot1) {
                        pstory("1. " + this->possible_loots_item[random_loot_linenum1].name);
                    }

                    //! 2nd loot
                    if(looted_loot1 && !looted_loot2) {
                        //? If the first loot is looted and this one isnt, then this is the first loot, and the original first loot doesnt exist anymore
                        pstory("1. " + this->possible_loots_item[random_loot_linenum2].name);
                    } else if(!looted_loot1 && !looted_loot2) {
                        //? If none were looted, then this is the second loot.
                        pstory("2. " + this->possible_loots_item[random_loot_linenum2].name);
                    } //? else if both were looted, we dont show them

                    //! 3rd loot
                    if(!looted_loot1 && !looted_loot2 && !looted_loot3) {
                        //? if none of the loots were looted, then this loot is the 3rd
                        pstory("3. " + this->possible_loots_item[random_loot_linenum3].name + creset);


                    } else if((!looted_loot1 && looted_loot2 && !looted_loot3) || (looted_loot1 && !looted_loot2 && !looted_loot3)) {
                        //? if ONE of the 3 loots were looted, then this is the 2nd
                        pstory("2. " + this->possible_loots_item[random_loot_linenum3].name + creset);

                    } else if((looted_loot1 && looted_loot2 && !looted_loot3)) {
                        //? if every loot were looted BUT this one, then we marked this as first
                        pstory("1. " + this->possible_loots_item[random_loot_linenum3].name + creset);

                    }

                    if(looted_loot1 && looted_loot2 && looted_loot3) {
                        item_choice = 5;
                        break;
                    }
                    std::cout << "(1-3) Take Item" << std::endl;
                    std::cout << "4. Take All" << std::endl;
                    std::cout << "5. Close" << std::endl;
                    std::cin >> item_choice;
                    if(item_choice == 1) player.add_to_inv(this->possible_loots_item[random_loot_linenum1]);
                }
            } else { 
                std::cout << "encountered an enemy and a loot at the same time" << std::endl;
            }
        }
    }while(o != 2);
}

EnemyPlace nerar_dummy_test("Place Test", std::vector<Character>{enemy_goblin, enemy_ghost, enemy_ogre}, std::vector<Weapon>{iron_dagger(), iron_katana(), zarvokh_claymore(), spartan_spear()}, std::vector<Item>{duty_paper, dummyItem1, dummyItem2, health_ring}, 2);