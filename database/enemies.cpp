#include "enemies.h"
#include "utils/classes_and_functions.h"
#include "weapons.h"

/*
std::string char_name,
	std::string char_class,
	int max_health,
	int max_mana,
	int max_endurance,
	int max_strength,
	int current_health,
	int current_mana,
	int current_endurance,
	int current_strength,
	int intelligence,
	int dexterity,
	int luck,
	int skill_longblade,
	int skill_shortblade,
	int skill_spear,
	int skill_bow,
	int skill_castspelltype_destructive,
	int skill_castspelltype_mystic,
	int skill_castspelltype_curse,
	const Weapon& weapon
*/

Character enemy_goblin("Goblin", "foe", 20, 0, 5, 3, 20, 0, 5, 3, 4, 5, 2, 15, 15, 5, 5, 0, 0, 0, rusty_dagger);
Character enemy_ogre("Ogre", "foe", 15, 5, 3, 5, 15, 5, 3, 5, 5, 10, 0, 5, 10, 20, 0, 0, 0, 0, stone_spear);
Character enemy_ghost("Ghost", "foe", 25, 5, 5, 10, 25, 5, 5, 10, 5, 15, 0, 5, 15, 5, 10, 0, 0, 0, iron_dagger);
Character enemy_bandit("Bandit", "foe", 20, 10, 5, 6, 20, 10, 5, 6, 5, 15, 5, 5, 5, 20, 0, 0, 0, 0, pointy_longstick);

Character enemy_ghost_of_yigmar_delli("The Ghost of Yigmar Delli", "foe", 40, 10, 10, 10, 40, 10, 10, 10, 15, 15, 0, 25, 10, 15, 5, 10, 5, 10, iron_katana_of_yigmar_delli);
