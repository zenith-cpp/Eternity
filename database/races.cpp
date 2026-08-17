#include <iostream>
#include "races.h"
// Template:
/*
char_name, char_class, max_health, max_mana,
max_endurance, max_strength, current_health,
current_mana, current_endurance, current_strength,
intelligence, dexterity, luck,
skill_longblade, skill_shortblade, skill_spear,
skill_bow, skill_castspelltype_destructive,
skill_castspelltype_mystic,
skill_castspelltype_curse,
const Weapon& weapon
*/

// Class Orc: Higher damage and health pool, specializes in long blades
// Class Elf: a LOT higher chance to hit enemies, specializes in bow and long range.
// Class High Elf: Smaller health and endurance pool, larger intelligence, dexterity and mana pool. Specializes in spells
// Class Viking: Mid health and strength pool, high-mid intelligence pool, high endurance.
// Class Warrior: Mid Health, high strength, low endurance and intelligence, but specializes in a lot of weapons


Character class_orc("Player", "orc", 40, 0, 6, 8, 40, 0, 6, 6, 2, 15, 2, 20, 5, 5, 0, 0, 0, 0, wooden_claymore);
Character class_elf("Player", "elf", 25, 5, 3, 2, 25, 5, 3, 2, 5, 20, 5, 5, 10, 0, 20, 10, 5, 0, twig_bow);
Character class_high_elf("Player", "high elf", 20, 20, 0, 2, 20, 20, 0, 2, 15, 20, 5, 0, 15, 0, 0, 20, 15, 15, training_sword);
Character class_viking("Player", "viking", 25, 5, 15, 6, 25, 5, 15, 6, 10, 15, 5, 25, 0, 0, 0, 0, 0, 0, wooden_claymore);
Character class_warrior("Player", "warrior", 25, 0, 0, 5, 25, 0, 0, 5, 5, 25, 10, 30, 20, 25, 15, 5, 5, 5, wooden_claymore);
