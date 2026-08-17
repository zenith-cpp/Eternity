#include <iostream>
#include "npcs.h"
#include "quests.h"
#include "utils/classes_and_functions.h"
#include "items.h"

Quest::Quest(std::string name) {
	this->name = name;
}

Quest quest_health_ring("health_ring");
Quest noQuest("no_quest");

bool dq_health_ring = false;
bool dq_find_fayee = false;

void Quest::start(NonPlayableCharacter& npc, Character& to) {
	if(this->name == "health_ring") {
		// Activate the health_ring quest
		pstory(yellow + npc.name + creset + ": Have you seen my " + green + health_ring.name + creset + "?");;
		int answer;
		std::cout << "1. Yes! [Hand over the " << green << health_ring.name << creset << "]" << std::endl;
		std::cout << "2. No.  " << std::endl;
		std::cout << "> ";
		std::cin >> answer;
		switch(answer) {
			case 1:
				c();
				if(to.has_item(health_ring)){
					to.remove_from_inv(health_ring);
					pstory(gray + "* You give " + npc.name + " the " + health_ring.name + ". He put in a good word for you in the shop. *");
					dq_health_ring = true;
					std::cin.ignore();
					return;
				} else {
					pstory(yellow + npc.name + creset + ": Liar! How could you lie to me like that?!");
					std::cin.ignore();
					return;
				}
				break;
			case 2:
				pstory(yellow + npc.name + creset + ": Ah, okay. Please let me know if you do find it.");
				break;
			default:
				break;
		}
		// TODO NEXT QUEST
	}
}
