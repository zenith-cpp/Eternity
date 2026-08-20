#include <iostream>
#include <cstdlib>
#include "database/weapons.h"
#include "database/utils/classes_and_functions.h"
#include "database/races.h"
#include "database/utils/colors.h"
#include "database/items.h"
#include "database/places.h"
#include "database/quests.h"
#include "database/structures.h"
#include "database/utils/listof_npcs.h"
#include "database/utils/listof_structures.h"

int main() {
	c();
	INITIALIZE_EVERYTHING(list_of_structures_nerar, list_of_npcs_nerar);
	pstory(gray + "*You wake up in a boat, 2 guards infront of you, going north.*");
	pstory("*You have a " + red + "headache" + gray + ", and have no idea where you're going, where you're coming from.*" + creset);
	pstory(green + "You" + creset + ": Where am I? Who are you two?");
	pstory(blue + "Guard 1" + creset + ": Oh, you're finally awake.");
	pstory(blue + "Guard 2" + creset + ": Hey there, what's your name?");
	pstory(green + "You" + creset + ": I... forgot. My head is about to explode.");
	pstory(blue + "Guard 1" + creset + ": *whispers* The potion worked.");
	pstory(blue + "Guard 2" + creset + ": *whispers back* Thank Azvokh.");
	pstory(gray + "*You pretend not to hear. Who knows what will happen?*" + creset);
	std::cout << "INSTRUCTION: Press ENTER to advance." << std::endl;
	std::cin.ignore();

	pstory(gray + "*Eventually, you see an island emerge from the fogs. The first structure you see is a castle.*");
	pstory("*You arrive*" + creset);
	pstory(blue + "Guard 1" + creset + ": Alright, we're finally here.");
	pstory(blue + "Guard 2" + creset + ": Come on, go inside you filthy scum!");
	pstory("*Go Inside?*");
	std::string answer;
	bool refused = false;
	std::cout << "<Y/N> ";
	std::cin >> answer;

	if(answer == "y" || answer == "Y") {
		pstory(gray + "*You comply.*");
	} else {
		pstory(blue + "Guard 1" + creset + ": Cute of you to think that you have an option.");
		pstory(gray + "*" + blue + "Guard 2" + gray + " points his spear, slightly piercing your throat. It hurts, but the wound isn't fatal.*");
		pstory("*You swallow your pride, and go in anyway, seeing that you have no other option.*" + creset);
		refused = true;
	}

	
	std::cin.ignore();
	std::cin.ignore();
	c();
	pstory(red + "???" + creset + ": Finally! We've been waiting for you.");
	if(refused) {
		pstory(gray + "*" + red + "???" + gray + " Noticed the small hole in your neck.*");
		pstory(red + "???" + creset + ": I see you got stung by one of our guards. Just know, commiting crimes and failing to comply with the guards is gonna result in something WAY worse.");
	}
	pstory(red + "Garokh, The High Elf" + creset + ": Anyways, I'm Garokh. I am in charge of a lot of things. Just know that I have power.");
	pstory(red + "Garokh, The High Elf" + creset + ": As you may or may not know, you have been released from prison.");
	pstory(red + "Garokh, The High Elf" + creset + ": Although, the higher authorities didn't give any reason, my hands are tied.");
	pstory(red + "Garokh, The High Elf" + creset + ": Before releasing you, you must answer my questions. I highly advise to answer with seriousness.");
	std::cin.ignore();
	c();
	std::string name;
	pstory(red + "Garokh, The High Elf" + creset + ": Please state your name.");
	std::cout << "My name is ";
	std::cin >> name;
	if(name.length() > 30 || name.length() < 2) {
		pstory(red + "Garokh, The High Elf" + creset + ": *sighs*. I told you to stop messing around, rat.");
		pstory(red + "Garokh, The High Elf" + creset + ": You know what? I don't got the patience for this shit.");
		pstory(red + "Garokh, The High Elf" + creset + ": Guards, kill him and throw him into the Akura river.");
		pstory(gray + "*You try running to no success. The first guard holds you down.*");
		pstory("*You desperately try to fight back, adrenaline pumping aggressively in your veins.*");
		pstory("*However, you are weak. You have no chance against highly-trained, geared up professionals.*");
		pstory("*The second guard pierces your legs over and over again. You... can't feel it anymore. You're paralyzed.*");
		pstory("*Once he is done, he goes for your chest. He pierces through your lungs.*");
		pstory("*The amount of adrenaline in your system keeps you alive. You feel EVERYTHING.*");
		std::cin.ignore();
		std::cin.ignore();
		c();
		pstory("*Your lung is full of blood, your scream echoes through the village of Nerar.*");
		pstory("*After what felt like ages, it's finally done. The guard goes for the final blow.*");
		pstory("*THEY DON'T MESS AROUND.*");
		pstory(red + "you died. try again." + creset);
		exit(0);
	}
	std::cin.ignore();
	// Class (race) selection
	int selected_race;
	Character player = Character("error", "error", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, training_sword);
	bool run = true;
	do{
		c();
		pstory(red + "Garokh, The High Elf" + creset + ": Alright. What's your race?");
		pstory(green + "1.      Orc\t\t6. Orc Stats");
		pstory(yellow + "2.      Elf\t\t7. Elf Stats");
		pstory(red + "3. High Elf\t\t8. High Elf Stats");
		pstory(blue + "4.   Viking\t\t9. Viking Stats");
		pstory(gray + "5.  Warrior\t\t10. Warrior Stats" + creset);
		
	
		std::cin >> selected_race;
		// Starting with the easy one: statistic printing
		switch(selected_race) {
			case 6:
				class_orc.print_stats();
				std::cout << "Press ENTER to go back..." << std::endl;
				std::cin.ignore();
				std::cin.ignore();
				break;
			case 7:
				class_elf.print_stats();
				std::cout << "Press ENTER to go back..." << std::endl;
				std::cin.ignore();
				std::cin.ignore();
				break;
			case 8:
				class_high_elf.print_stats();
				std::cout << "Press ENTER to go back..." << std::endl;
				std::cin.ignore();
				std::cin.ignore();
				break;
			case 9:
				class_viking.print_stats();
				std::cout << "Press ENTER to go back..." << std::endl;
				std::cin.ignore();
				std::cin.ignore();
				break;
			case 10:
				class_warrior.print_stats();
				std::cout << "Press ENTER to go back..." << std::endl;
				std::cin.ignore();
				std::cin.ignore();
				break;
			case 1:
				player = class_orc;
				run = false;
				break;
			case 2:
				player = class_elf;
				run = false;
				break;
			case 3:
				player = class_high_elf;
				run = false;
				break;
			case 4:
				player = class_viking;
				run = false;
				break;
			case 5:
				player = class_warrior;
				run = false;
				break;
		}
	} while(run);
	player.char_name = name;

	c();
	pstory(red + "Garokh, The High Elf" + creset + ": Hmm... " + player.char_class + "? Oh yeah, you kinda look like one.");
	pstory(red + "Garokh, The High Elf" + creset + ": Alright " + player.char_name + ", The " + player.char_class + ". You are released.");
	pstory(red + "Garokh, The High Elf" + creset + ": Here are your papers. Please take care of them as you need to show them to the guard upfront.");
	player.add_to_inv(release_paper);
	int option;
	run = true;
	do {
		std::cout << "INSTRUCTION: Throughout the gameplay you will see the option `inventory`. When you see that, you can freely open and close your inventory without any consequences. Try it!" << std::endl;
		std::cout << "INSTRUCTION: After opening your inventory, press `ENTER` to close it." << std::endl;
		std::cout << blue << "1. Inventory" << creset << std::endl;
		std::cout << blue << "2. Proceed forward" << creset << std::endl;
		std::cin >> option;
		if(option == 1) {
			player.open_inv();
			c();
		} else {
			run = false;
		}
	} while(run);
	std::cin.ignore();
	c();
	// reusing variables to avoid declaring new 1-time-use variables
	run = true;
	option = 0;
	bool already_looted_b2 = false;
	pstory(gray + "*You're on the castle yard. Choose your next move.*" + creset);
	do {
		std::cout << blue << "1. Open Barrel #1." << creset << std::endl;
		std::cout << blue << "2. Open Barrel #2." << creset << std::endl;
		std::cout << blue << "3. Open Barrel #3." << creset << std::endl;
		std::cout << blue << "4. Proceed forward to the front office." << creset << std::endl;
		std::cout << blue << "5. Open Inventory" << creset << std::endl;
		std::cin >> option;
		c();
		if(option == 1 || option == 3) {
			pstory(red + "Barrel is empty." + creset); // yes it is hardcoded and not rng im sorry
			std::cin.ignore();
		} else if(option == 2) {
			if(already_looted_b2) {
				pstory(red + "Barrel is empty." + creset);
				std::cin.ignore();
			} else {
				pstory(green + "You found a " + health_ring.name + "! Take?");
				std::string option_str;
				std::cout << "<Y/n> ";
				std::cin >> option_str;
				if(option_str == "y" || option_str == "Y") {
					player.add_to_inv(health_ring);
					already_looted_b2 = true;
					std::cin.ignore();
				} else {
					pstory(gray + "*You pass on the offer.*" + creset);
					std::cin.ignore();
				}
			}
		} else if(option == 4) {
			run = false;
		} else if(option == 5) {
			player.open_inv();
		}
	}while(run);

	c();
	pstory(yellow + "Front Guard" + creset + ": Hello there, I was expecting you.");
	pstory(yellow + "Front Guard" + creset + ": I hope you have the release paper. Without it, I can't let you go.");
	pstory(yellow + "Front Guard" + creset + ": Let me check your pockets.");
	std::cin.ignore();
	std::cin.ignore();
	pstory(gray + "*Checks your pockets*" + creset);
	if(!player.has_item(release_paper)) {
		pstory(yellow + "Front Guard" + creset + ": There is nothing in your pockets. I can't believe you just...");
		pstory(yellow + "Front Guard" + creset + ": Discarded something that important. You are too incompetent.");
		pstory(yellow + "Front Guard" + creset + ": I won't kill you, since I am in a good mood today, however...");
		pstory(yellow + "Front Guard" + creset + ": I will ship you back to the prison you were meant to get released from.");
		pstory(gray + "*You were shipped back, and never returned*" + creset);
		exit(0);
	}
	pstory(yellow + "Front Guard" + creset + ": Ah! Here it is.");
	pstory(yellow + "Front Guard" + creset + ": Let me check this real quick. Just to make sure.");
	pstory(yellow + "Front Guard" + creset + ": Alright, nothing suspicious. You can go.");
	pstory(yellow + "Front Guard" + creset + ": Almost forgot! The higher authorities gave me this note.");
	pstory(yellow + "Front Guard" + creset + ": No idea what's inside, but I recommend you read it.");
	player.add_to_inv(duty_paper);
	std::cin.ignore();
	c();
	pstory(gray + "*You have been released to the village of Nerar.*" + creset);
	main_ui(player);

	return 0;
}
