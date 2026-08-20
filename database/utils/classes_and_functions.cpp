#include "classes_and_functions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>
#include "colors.h"
#include "../structures.h"
#include "listof_npcs.h"



Character::Character(
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
)
	: char_name(char_name),
      char_class(char_class),
      max_health(max_health),
      max_mana(max_mana),
      max_endurance(max_endurance),
      max_strength(max_strength),
      current_health(current_health),
      current_mana(current_mana),
      current_endurance(current_endurance),
      current_strength(current_strength),
      intelligence(intelligence),
      weapon(weapon),
      dexterity(dexterity),
      luck(luck),
      skill_longblade(skill_longblade),
      skill_shortblade(skill_shortblade),
      skill_bow(skill_bow),
      skill_spear(skill_spear),
      skill_castspelltype_destructive(skill_castspelltype_destructive),
      skill_castspelltype_mystic(skill_castspelltype_mystic),
      skill_castspelltype_curse(skill_castspelltype_curse),
	  personality(40)
{
	overall_damage = max_strength / 2 + this->weapon.damage;
	inventory = {};
};

int Character::get_weapon_skillpoint() {
	if(this->weapon.type == "skill_longblade") {
		return this->skill_longblade;
	} else if(this->weapon.type == "skill_shortblade") {
		return this->skill_shortblade;
	} else if(this->weapon.type == "skill_spear") {
		return this->skill_spear;
	} else if(this->weapon.type == "skill_bow") {
		return this->skill_bow;
	} else {
		std::cout << "Possible Dev Mistake: Using get_weapon_skillpoint too early. Assuming no weapon, returning 0." << std::endl;
		return 0;
	}
}

void Character::heal(int amount) {
	this->current_health += amount;
	if(this->current_health > this->max_health) {
		int total_amount_healed = amount - (this->current_health - this->max_health);
		this->current_health = this->max_health;
		std::cout << "Successfully healed " << green << total_amount_healed << " HP" << creset << std::endl;
		return;
	}
	
	std::cout << "Successfully healed " << green << amount << " HP" << creset << std::endl;
}

void Character::attack(Character &target) {
	srand(time(nullptr));
	int attack_chance = dexterity + luck + (this->get_weapon_skillpoint()/2);

	if(rand() % 100 < attack_chance) {
		int damage_dealt = this->overall_damage - (target.current_endurance / 2.5);
		if(damage_dealt < 0) {
			// When this case is triggered, it usually means that the target's endurance was MASSIVE compared to the
			// overall_damage. It means that the player or foe is too weak for their enemy;
			damage_dealt = 0;
		}
		target.current_health -= damage_dealt;

		std::cout << green << "Attack Success!" << creset << std::endl;
		std::cout << this->char_name << " Struck " << target.char_name << ", dealing " << red << damage_dealt << creset << " damage." << std::endl;

		return;
	}
	
	std::cout << red << "Attack Missed." << creset << std::endl;
}

void Character::print_stats() {
	std::cout << green << "Name      				   : " << creset << this->char_name  					   << std::endl;
	std::cout << green << "Class     				   : " << creset<< this->char_class 					   << std::endl;
	std::cout << green << "Max Health				   : " << creset<< this->max_health 					   << std::endl;
	std::cout << green << "Max Mana  				   : " << creset<< this->max_mana   					   << std::endl;
	std::cout << green << "Endurance 				   : " << creset << this->max_endurance 				   << std::endl;	
	std::cout << green << "Strength  				   : " << creset << this->max_strength  				   << std::endl;
	std::cout << green << "Intelligence 			   : " << creset << this->intelligence 				   << std::endl;
	std::cout << green << "Dexterity				   : " << creset << this->dexterity 					   << std::endl;
	std::cout << magenta << "\t\tWeapon Skills" << creset << std::endl;
	std::cout << green << "Long Blade				   : " << creset << this->skill_longblade 				   << std::endl;
	std::cout << green << "Short Blade				   : " << creset << this->skill_shortblade 			   << std::endl;
	std::cout << green << "Spear      				   : " << creset << this->skill_spear 					   << std::endl;
	std::cout << green << "Bow        				   : " << creset << this->skill_bow                       << std::endl;
	std::cout << green << "Cast Spell Type: Destructive: " << creset << this->skill_castspelltype_destructive << std::endl;
	std::cout << green << "Cast Spell Type: Mystic     : " << creset<< this->skill_castspelltype_mystic      << std::endl;
	std::cout << green << "Cast Spell Type: Curse      : " << creset<< this->skill_castspelltype_curse       << std::endl;
	std::cout << magenta << "\t\t Weapon Information" << creset << std::endl;
	std::cout << green << "Starter Weapon              : " << creset << this->weapon.name                     << std::endl;
	std::cout << green << "Weapon Type                 : " << creset << this->weapon.type << std::endl;
	std::cout << green << "Weapon Damage               : " << creset << this->weapon.damage << std::endl;
}



void c() {
	system("clear || cls");
}

void pstory(std::string story) {
	std::cout << "\t\t" << story << std::endl;
}


void Character::add_to_inv(Item item) {
	size_t size = this->inventory.size();
	if(size < 20){
		this->inventory.push_back(item);
		pstory(green + "[+] " + item.name + creset);
		return;
	}
	pstory(red + "Inventory Full." + creset);
}

void Character::remove_from_inv(Item item) {
	size_t size = this->inventory.size();
	if(this->inventory.empty()) {
		pstory(red + "Inventory Empty." + creset);
		std::cin.ignore();
		return;
	}
	for(size_t i = 0; i<size; i++) {
		if(this->inventory[i].name == item.name) {
			this->inventory.erase(this->inventory.begin() + i);
			pstory(red + "[-] " + item.name + creset);
			return;
		}
	}
	pstory(red + "Item `" + item.name + "` not found." + creset);
}

void Character::open_inv() {
	bool run = true;
	int option;
	int number_to_exit;
	do {
		c();
		pstory("\t\t\tINVENTORY");
		pstory("ITEM\t\t\t\t\t\tPERK");
		bool mhp_exists = false; // mhp = Max Health Plus.
		bool mep_exists = false;
		bool msp_exists = false;
		if(this->inventory.empty()) {
			pstory(red + "Inventory Empty." + creset);
			std::cin.ignore();
			return;
		}
		for(size_t i=0; i<this->inventory.size(); i++) {		
			
			// Calculating perks
			std::cout << "\t\t" << this->inventory[i].name << "\t\t\t\t\t";
			if(this->inventory[i].max_health_plus != 0) {
				// So either a negative or a positive number
				mhp_exists = true;
				std::cout << "Max Health: " << (this->inventory[i].max_health_plus < 0 ? red : green) << this->inventory[i].max_health_plus << creset << " ";
			}
			if(this->inventory[i].max_endurance_plus != 0) {
				mep_exists = true;
				std::cout << "Max Endurance: " << (this->inventory[i].max_endurance_plus < 0 ? red : green) << this->inventory[i].max_endurance_plus << creset << " ";
			}
			if(this->inventory[i].max_strength_plus != 0) {
				msp_exists = true;
				std::cout << "Max Strength: " << (this->inventory[i].max_strength_plus < 0 ? red : green) << this->inventory[i].max_strength_plus << creset << " ";
			}

			if (!mhp_exists && !mep_exists && !msp_exists) {
				std::cout << gray << "Nothing" << creset << std::endl;
			}
			std::cout << std::endl;
		}

		
		int number_in_line = 1;
		for(size_t i=0; i<this->inventory.size(); i++) {
			std::cout << red << number_in_line << ". Discard Item " << this->inventory[i].name << ". (This action is irreversable)" << creset << std::endl;
			number_in_line++;
		}
		std::cout << this->inventory.size()+1 << ". Exit Inventory" << std::endl;
		number_to_exit = this->inventory.size()+1;
		
		std::cout << "> ";
		std::cin >> option;
		if(option == number_to_exit) {run = false;}
		if(option <= this->inventory.size() && option > 0) {
			for(size_t i=0; i<this->inventory.size(); i++) {
				if(i+1 == option) {
					this->remove_from_inv(this->inventory[i]);
					std::cout << "Press ENTER to proceed" << std::endl;
					std::cin.ignore();
					c();
				} else {
					std::cout << "Item has already been discarded." << std::endl;
				}
			}
		}
	} while(run);
}

bool Character::has_item(Item item) {
	size_t size = this->inventory.size();
	if(this->inventory.empty()) return false;
	for(int i=0; i<size; i++) {
		if(this->inventory[i].name == item.name) {
			return true;
		}
	}
	return false;
}

//! Expand this whenever you add new places
void print_structures(std::string current_place) {

    if (current_place == nerar.name) {

        for (size_t i = 0; i < nerar.list_of_structures.size(); i++) {
            std::cout << nerar.list_of_structures[i].name << '\n';
        }
    } else {
        std::cout << "* This place is empty. There are no structures nearby. *\n";
    }

    std::cout << "EXITED print_structures\n";
}

//! Expand this whenever you add new npcs
int select_npc(std::string current_place) {
	//? FOR NERAR NPCS
	int choice = 0;
	if(current_place == nerar.name) {
		for(int i=0; i<nerar.list_of_npcs.size(); i++) {
			std::cout << i+1 << ". " << nerar.list_of_npcs[i].name << std::endl;
		}
		int choice;
		std::cout << "> ";
		std::cin >> choice;

	} else if(current_place == nerar_arys_shop.name) {
		for(int i=0; i<nerar_arys_shop.list_of_npcs.size(); i++) {
			std::cout << nerar_arys_shop.list_of_npcs[i].name << std::endl;
		}
		int choice;
		std::cout << "> ";
		std::cin >> choice;
	} else if(current_place == nerar_glarys_shop.name) {
		for(int i=0; i<nerar_glarys_shop.list_of_npcs.size(); i++) {
			std::cout << nerar_glarys_shop.list_of_npcs[i].name << std::endl;
		}
		int choice;
		std::cout << "> ";
		std::cin >> choice;
	} else if(current_place == nerar_blacksmith.name) {
		for(int i=0; i<nerar_blacksmith.list_of_npcs.size(); i++) {
			std::cout << nerar_blacksmith.list_of_npcs[i].name << std::endl;
		}
		int choice;
		std::cout << "> ";
		std::cin >> choice;
	} else if(current_place == nerar_frontguard_office.name) {
		for(int i=0; i<nerar_frontguard_office.list_of_npcs.size(); i++) {
			std::cout << nerar_frontguard_office.list_of_npcs[i].name << std::endl;
		}
		int choice;
		std::cout << "> ";
		std::cin >> choice;
	}
	//? FOR ... NPCS

	return choice-1;
}


void main_ui(Character& player) {
	int option;
	do{
		c();
		std::cout << "1. Speak to NPCS     (LIST)" << std::endl;
		std::cout << "2. Explore           (LIST)" << std::endl;
		std::cout << "3. Read Papers       (LIST)" << std::endl;
		std::cout << "4. Quick Travel      (LIST)" << std::endl;
		std::cout << "5. Open Inventory" << std::endl;
		std::cout << "9. Exit Game" << std::endl;
		std::cout << "> ";
		std::cin >> option;
		// first, the easiest ones, then the hardest ones
		if(option == 5) {
			c();
			player.open_inv();
		} else if(option == 1) {
			c();
			if(player.current_location.name == nerar.name && player.current_structure_location.name == "") {
				int user_choice = select_npc(player.current_location.name);
				list_of_npcs_nerar[user_choice].talk(player);


			} else if(player.current_structure_location.name == nerar_arys_shop.name){
				int user_choice = select_npc(player.current_structure_location.name);
				list_of_npcs_nerar_arys_shop[user_choice].talk(player);


			} else if(player.current_structure_location.name == nerar_blacksmith.name) {
				int user_choice = select_npc(player.current_structure_location.name);
				list_of_npcs_nerar_arys_shop[user_choice].talk(player);


			} else if(player.current_structure_location.name == nerar_glarys_shop.name) {
				int user_choice = select_npc(player.current_structure_location.name);
				list_of_npcs_nerar_arys_shop[user_choice].talk(player);
			
			
			} //! More locations / structures IF added
		} else if(option == 3) {
			c();
			int lineCounter = 1;
			std::vector<Item> papers = {};
			for(size_t i=0; i<player.inventory.size(); i++) {

				if(player.inventory[i].content != "") {

					std::cout << lineCounter << ". " << player.inventory[i].name << std::endl;
					papers.push_back(player.inventory[i]);
					lineCounter++;

				}
			}
			if(lineCounter == 1) {
				// Then there is no papers to read
				pstory(gray + "* No papers to read..." + creset);
				pstory("Press ENTER to go back");
				std::cin.ignore();
				continue;
			}
			int selectedPaper;
			std::cout << lineCounter + 1 << ". Go Back" << std::endl;
			std::cout << "> ";
			std::cin >> selectedPaper;
			if(selectedPaper == lineCounter+1) continue;
			if(selectedPaper > 0 && selectedPaper <= lineCounter) {
				papers[selectedPaper-1].read();
				continue;
			} else {
				pstory(red + "Option `" + std::to_string(selectedPaper) + "` is non-existent.");
				std::cin.ignore();
				std::cin.ignore();
				continue;
			}

		} else if(option == 4) {
			c();
			pstory("No Places to quick travel to currently. This is under development.");
			std::cin.ignore();
			std::cin.ignore();
		}
	}while(option != 9);
}




void INITIALIZE_EVERYTHING(std::vector<Structure> list_of_structures_nerar, std::vector<NonPlayableCharacter> list_of_npcs_nerar) {
	// Initializing places:
	nerar.list_of_structures = list_of_structures_nerar;
	nerar.list_of_npcs 		 = list_of_npcs_nerar;
}