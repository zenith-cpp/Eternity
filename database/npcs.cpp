#include "npcs.h"
#include "utils/classes_and_functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

NonPlayableCharacter::NonPlayableCharacter(std::string name, std::vector<std::string> random_dialogues, Quest quest) :
name(name), random_dialogues(random_dialogues), quest(quest)
{
    
}

void NonPlayableCharacter::initialize(Character player) {
    this->respect = player.personality;
    if(this->respect > 100) {this->respect = 100;} // prevent overflow
    // respect dialogue algorithm
    if(this->respect >= 30 && this->respect <= 60) {
        // When respect ranges from 30-60
        this->random_dialogues = dialogue_cv_general;
    } else if(this->respect >= 61 && this->respect <= 100) {
        this->random_dialogues = dialogue_cv_general_respectsPlayer;
    } else if(this->respect < 30) {
        this->random_dialogues = dialogue_cv_general_hatesPlayer;
    }
}

void NonPlayableCharacter::talk(Character player) {
    std::srand(std::time(nullptr));
    int random_dialogue_index = std::rand() % this->random_dialogues.size();
    this->initialize(player);

    for(int i=0; i<this->random_dialogues.size(); i++) {
        if(i == random_dialogue_index) {
            std::cout << this->random_dialogues[i] << std::endl;
            return;
        }
    }
}

// getting the basics down, however the rest of the information requires the statistics of the player
NonPlayableCharacter nerar_tovari("Tovari", std::vector<std::string>{}, quest_health_ring);
NonPlayableCharacter nerar_civilian_01("Civilian 1", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_civilian_02("Civilian 2", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_civilian_03("Civilian 3", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_arysshop_ary("Ary", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_glarysshop_glary("Glary", std::vector<std::string>{}, noQuest);
NonPlayableCharacter nerar_blacksmith_srayum("Srayum", std::vector<std::string>{}, noQuest);