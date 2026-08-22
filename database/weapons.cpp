#include <iostream>
#include "weapons.h"

Weapon::Weapon(std::string name, std::string type, int damage) {
	this->name = name;
	this->type = type;
	this->damage = damage;
}


// Short sword assigning (declared at /database/weapons.h)
Weapon training_sword("Training Sword", "skill_shortblade", 3);
Weapon rusty_dagger("Rusty Dagger", "skill_shortblade", 5);
Weapon iron_dagger("Iron Dagger", "skill_shortblade", 7);
Weapon diamond_dagger("Diamond Dagger", "skill_shortblade", 12);
Weapon obsidian_dagger("Obsidian Dagger", "skill_shortblade", 15);
Weapon energy_imbued_iron_dagger("Energy Imbued Iron Dagger", "skill_shortblade", 20);
Weapon zarvokh_dagger("Zarvokh Dagger", "skill_shortblade", 25);
Weapon zarvokh_shortsword("Zarvokh Shortsword", "skill_shortblade", 28);

// Long blades
Weapon wooden_claymore("Wooden Claymore", "skill_longblade", 4);
Weapon iron_katana("Iron Katana", "skill_longblade", 7);
Weapon orcstone_broadsword("Orcstone Broadsword", "skill_longblade", 10);
Weapon obsidian_claymore("Obisidian Claymore", "skill_longblade", 17);
Weapon fiery_katana("Fiery Katana", "skill_longblade", 22);
Weapon zarvokh_katana("Zarvokh Katana", "skill_longblade", 27);
Weapon zarvokh_claymore("Zarvokh Claymore", "skill_longblade", 30);

// Special Long Blades
Weapon iron_katana_of_yigmar_delli("The Iron Katana of Yigmar Delli", "skill_longblade", 16);

// Spears
Weapon pointy_longstick("Pointy Longstick", "skill_spear", 4);
Weapon stone_spear("Stone Spear", "skill_spear", 6);
Weapon iron_spear("Iron Spear", "skill_spear", 9);
Weapon spartan_spear("Spartan Spear", "skill_spear", 14);
Weapon obsidian_spear("Obsidian Spear", "skill_spear", 18);
Weapon rage_enhanced_spartan_spear("Rage Enhanced Spartan Spear", "skill_spear", 25);
Weapon zarvokh_spear("Zarvokh Spear", "skill_spear", 32);

// Bows
Weapon twig_bow("Twig Bow", "skill_bow", 2); // ranged tho
Weapon crafted_bow("Crafted Bow", "skill_bow", 5);
Weapon blacksmith_bow("Blacksmith Bow", "skill_bow", 8);
Weapon mechanical_bow("Mechanical Bow", "skill_bow", 14);
