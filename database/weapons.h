#pragma once
#include <string>

class Weapon {
public:
	std::string name;
	std::string type;
	int damage;

	Weapon(): name("No Name"), type("No Type"), damage(0) {}

	Weapon(std::string name, std::string type, int damage); // Constructor
};

// Short sword assigning (declared at /database/weapons.h)
Weapon& training_sword();
Weapon& rusty_dagger();
Weapon& iron_dagger();
Weapon& diamond_dagger();
Weapon& obsidian_dagger();
Weapon& energy_imbued_iron_dagger();
Weapon& zarvokh_dagger();
Weapon& zarvokh_shortsword();

// Long blades
Weapon& wooden_claymore();
Weapon& iron_katana();
Weapon& orcstone_broadsword();
Weapon& obsidian_claymore();
Weapon& fiery_katana();
Weapon& zarvokh_katana();
Weapon& zarvokh_claymore();

// Special Long Blades
Weapon& iron_katana_of_yigmar_delli();

// Spears
Weapon& pointy_longstick();
Weapon& stone_spear();
Weapon& iron_spear();
Weapon& spartan_spear();
Weapon& obsidian_spear();
Weapon& rage_enhanced_spartan_spear();
Weapon& zarvokh_spear();

// Bows
Weapon& twig_bow();
Weapon& crafted_bow();
Weapon& blacksmith_bow();
Weapon& mechanical_bow();
