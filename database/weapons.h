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

<<<<<<< HEAD
// Short swords
extern Weapon training_sword;
extern Weapon rusty_dagger;
extern Weapon iron_dagger;
extern Weapon diamond_dagger;
extern Weapon obsidian_dagger;
extern Weapon energy_imbued_iron_dagger;
extern Weapon zarvokh_dagger;
extern Weapon zarvokh_shortsword;

// Long swords
extern Weapon wooden_claymore;
extern Weapon iron_katana;
extern Weapon orcstone_broadsword;
extern Weapon obsidian_claymore;
extern Weapon fiery_katana;
extern Weapon zarvokh_katana;
extern Weapon zarvokh_claymore;

extern Weapon iron_katana_of_yigmar_delli;

// Spears
extern Weapon pointy_longstick;
extern Weapon stone_spear;
extern Weapon iron_spear;
extern Weapon spartan_spear;
extern Weapon obsidian_spear;
extern Weapon rage_enhanced_spartan_spear;
extern Weapon zarvokh_spear;

// Bow
extern Weapon twig_bow;
extern Weapon crafted_bow;
extern Weapon blacksmith_bow;
extern Weapon mechanical_bow;
// To be continued maybe, idk, I can't larp bows
=======
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
>>>>>>> 0d3aa7e (PATCH: Fixed initialization issue. Combat works now. Can't say the same for the looting system, though)
