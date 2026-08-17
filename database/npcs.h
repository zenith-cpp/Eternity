#pragma once
#include <vector>
#include "quests.h"
#include "utils/dialogues.h"



class Character;
class NonPlayableCharacter {
public:
	std::string name;
	std::vector<std::string> random_dialogues;
	Quest quest;
	int respect;

	NonPlayableCharacter(std::string name, std::vector<std::string> random_dialogues, Quest quest);

	void initialize(Character player);
	void talk(Character player);
};

extern NonPlayableCharacter nerar_tovari;
extern NonPlayableCharacter nerar_civilian_01;
extern NonPlayableCharacter nerar_civilian_02;
extern NonPlayableCharacter nerar_civilian_03;
extern NonPlayableCharacter nerar_arysshop_ary; // `Ary` from `Ary's shop`
extern NonPlayableCharacter nerar_glarysshop_glary;
extern NonPlayableCharacter nerar_blacksmith_srayum;