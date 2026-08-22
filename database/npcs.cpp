#include "npcs.h"
#include "utils/classes_and_functions.h"
#include "utils/rumors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

NonPlayableCharacter::NonPlayableCharacter(std::string name, std::vector<std::string> random_dialogues, Quest quest) :
name(name), random_dialogues(random_dialogues), quest(quest)
{
    
}

void NonPlayableCharacter::initialize(Character player) {
    this->respect = player.personality;
    if(this->name == "Tovari" && dq_health_ring) this->respect += 20;
    if(this->respect > 100) {this->respect = 100;} // prevent overflow
    // respect dialogue algorithm
    if(this->respect >= 30 && this->respect < 60) {
        // When respect ranges from 30-60
        this->random_dialogues = dialogue_cv_general;
    } else if(this->respect >= 60 && this->respect <= 100) {
        this->random_dialogues = dialogue_cv_general_respectsPlayer;
    } else if(this->respect < 30) {
        this->random_dialogues = dialogue_cv_general_hatesPlayer;
    }
}

void NonPlayableCharacter::talk(Character player) {
    c();
    this->initialize(player);
    std::srand(std::time(nullptr));
    int random_dialogue_index = std::rand() % this->random_dialogues.size();

    
    if(this->name == "Tovari" && dq_health_ring == false) {
        quest_health_ring.start(this, player);
        return;
    }
    
    int p_option;
    do {
        c();
        std::cout << "RESPECT FOR YOU: " << (this->respect < 50 ? red : green) << this->respect << creset << "/100" << std::endl;
        for(int i=0; i<this->random_dialogues.size(); i++) {
            if(i == random_dialogue_index) {
                pstory(cyan + this->name + creset + ": " + this->random_dialogues[i]);
            }
        }

        std::cout << "1. Can you tell me some rumors?" << std::endl;
        std::cout << "2. Nevermind." << std::endl;
        std::cin >> p_option;

        if(p_option == 1) {
            if(this->respect < 30) {

                pstory(cyan + this->name + creset + ": Why would I tell you anything? Get lost.");
                std::cout << gray << "*He walked away.*" << creset << std::endl;
                std::cin.ignore();
                return;

            } else if(this->respect >= 30) {

                pstory(cyan + this->name + creset + ": Okay, hmmm, let's see...");
                int random_rumor_index = std::rand() % rumors.size();

                for(size_t i=0; i<rumors.size(); i++) {

                    if(i == random_rumor_index) {
                        pstory(cyan + this->name + creset + ": " + rumors[i]);
                        std::cin.ignore();
                        std::cin.ignore();
                    }

                }
            }
        }
    }while(p_option != 2);
}

// getting the basics down, however the rest of the information requires the statistics of the player
NonPlayableCharacter nerar_tovari("Tovari", std::vector<std::string>{}, quest_health_ring);
NonPlayableCharacter nerar_civilian_01("Civilian 1", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_civilian_02("Civilian 2", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_civilian_03("Civilian 3", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_arysshop_ary("Ary", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_glarysshop_glary("Glary", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_blacksmith_srayum("Srayum", std::vector<std::string>{}, noQuest);