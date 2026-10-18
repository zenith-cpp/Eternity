#include <iostream>
#include "weapons.h"

Weapon::Weapon(std::string name, std::string type, int damage) {
	this->name = name;
	this->type = type;
	this->damage = damage;
}


// Short sword assigning (declared at /database/weapons.h)
<<<<<<< HEAD
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
=======
Weapon& training_sword() {
    static Weapon weapon("Training Sword", "skill_shortblade", 3);
    return weapon;
}
Weapon& rusty_dagger() {
    static Weapon weapon("Rusty Dagger", "skill_shortblade", 5);
    return weapon;
}
Weapon& iron_dagger() {
    static Weapon weapon("Iron Dagger", "skill_shortblade", 7);
    return weapon;
}
Weapon& diamond_dagger() {
    static Weapon weapon("Diamond Dagger", "skill_shortblade", 12);
    return weapon;
}
Weapon& obsidian_dagger() {
    static Weapon weapon("Obsidian Dagger", "skill_shortblade", 15);
    return weapon;
}
Weapon& energy_imbued_iron_dagger() {
    static Weapon weapon("Energy Imbued Iron Dagger", "skill_shortblade", 20);
    return weapon;
}
Weapon& zarvokh_dagger() {
    static Weapon weapon("Zarvokh Dagger", "skill_shortblade", 25);
    return weapon;
}
Weapon& zarvokh_shortsword() {
    static Weapon weapon("Zarvokh Shortsword", "skill_shortblade", 28);
    return weapon;
}


// Long blades
Weapon& wooden_claymore() {
    static Weapon weapon("Wooden Claymore", "skill_longblade", 4);
    return weapon;
}
Weapon& iron_katana() {
    static Weapon weapon("Iron Katana", "skill_longblade", 7);
    return weapon;
}
Weapon& orcstone_broadsword() {
    static Weapon weapon("Orcstone Broadsword", "skill_longblade", 10);
    return weapon;
}
Weapon& obsidian_claymore() {
    static Weapon weapon("Obisidian Claymore", "skill_longblade", 17);
    return weapon;
}
Weapon& fiery_katana() {
    static Weapon weapon("Fiery Katana", "skill_longblade", 22);
    return weapon;
}
Weapon& zarvokh_katana() {
    static Weapon weapon("Zarvokh Katana", "skill_longblade", 27);
    return weapon;
}
Weapon& zarvokh_claymore() {
    static Weapon weapon("Zarvokh Claymore", "skill_longblade", 30);
    return weapon;
}


// Special Long Blades
Weapon& iron_katana_of_yigmar_delli() {
    static Weapon weapon("The Iron Katana of Yigmar Delli", "skill_longblade", 16);
    return weapon;
}


// Spears
Weapon& pointy_longstick() {
    static Weapon weapon("Pointy Longstick", "skill_spear", 4);
    return weapon;
}
Weapon& stone_spear() {
    static Weapon weapon("Stone Spear", "skill_spear", 6);
    return weapon;
}
Weapon& iron_spear() {
    static Weapon weapon("Iron Spear", "skill_spear", 9);
    return weapon;
}
Weapon& spartan_spear() {
    static Weapon weapon("Spartan Spear", "skill_spear", 14);
    return weapon;
}
Weapon& obsidian_spear() {
    static Weapon weapon("Obsidian Spear", "skill_spear", 18);
    return weapon;
}
Weapon& rage_enhanced_spartan_spear() {
    static Weapon weapon("Rage Enhanced Spartan Spear", "skill_spear", 25);
    return weapon;
}
Weapon& zarvokh_spear() {
    static Weapon weapon("Zarvokh Spear", "skill_spear", 32);
    return weapon;
}


// Bows
Weapon& twig_bow() {
    static Weapon weapon("Twig Bow", "skill_bow", 2);
    return weapon;
}
Weapon& crafted_bow() {
    static Weapon weapon("Crafted Bow", "skill_bow", 5);
    return weapon;
}
Weapon& blacksmith_bow() {
    static Weapon weapon("Blacksmith Bow", "skill_bow", 8);
    return weapon;
}
Weapon& mechanical_bow() {
    static Weapon weapon("Mechanical Bow", "skill_bow", 14);
    return weapon;
}
>>>>>>> 0d3aa7e (PATCH: Fixed initialization issue. Combat works now. Can't say the same for the looting system, though)
