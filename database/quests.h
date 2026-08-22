#pragma once
#include <iostream>
#include "utils/colors.h"

class NonPlayableCharacter; // forward declaration
class Character;

class Quest {
public:
	std::string name;

	Quest(std::string name);
	void start(NonPlayableCharacter* npc, Character& to);
};

extern Quest quest_health_ring;
extern Quest noQuest; // for ordinary civilians that dont give tasks


extern bool dq_health_ring; // dq - did quest
extern bool dq_find_fayee;
