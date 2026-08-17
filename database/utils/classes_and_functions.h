#pragma once
#include <string>
#include <cstdlib>
#include <vector>
#include "../weapons.h"
#include "../items.h"
#include "../places.h"

extern std::vector<Structure> list_of_structures_nerar;
class Character {
public:
	std::string char_name; // ex. `Goblin` or `Player12`
	std::string char_class; // For foes it's simply `beast`
	int max_health;
	int max_mana;
	int max_endurance;
	int max_strength;
	int current_health;
	int current_mana;
	int current_endurance;
	int current_strength;
	int intelligence;
	int dexterity;
	int luck;
	int overall_damage;
	// skills
	int skill_longblade;
	int skill_shortblade;
	int skill_spear;
	int skill_bow;
	int skill_castspelltype_destructive;
	int skill_castspelltype_mystic;
	int skill_castspelltype_curse;
	Weapon weapon;
	std::vector<Item> inventory;
	int personality;
	Place current_location;
	Structure current_structure_location;
	

	Character(std::string char_name, std::string char_class, int max_health, int max_mana, int max_endurance,
	int max_strength, int current_health, int current_mana, int current_endurance, int current_strength,
	int intelligence, int dexterity, int luck, int skill_longblade, int skill_shortblade,
	int skill_spear, int skill_bow, int skill_castspelltype_destructive, int skill_castspelltype_mystic,
	int skill_castspelltype_curse, const Weapon& weapon); // Constructer
	// So many parameters

	int get_weapon_skillpoint(); // For determining attack chance
	void heal(int amount);
	void attack(Character &target);
	void print_stats();
	void add_to_inv(Item item);
	void remove_from_inv(Item item);
	void open_inv();
	bool has_item(Item item);
};


void c();
void pstory(std::string story);
void main_ui(std::string place, Character& player); // `place` as in Nerar e.g.
void print_structures(std::string current_location);
void print_npcs(std::string current_location);

void INITIALIZE_EVERYTHING(std::vector<Structure> list_of_structures_nerar, std::vector<NonPlayableCharacter> list_of_npcs_nerar);