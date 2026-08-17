#include <iostream>
#include "items.h"
#include "utils/classes_and_functions.h"

Item::Item(std::string name, bool is_equipped, int max_health_plus, int max_endurance_plus, int max_strength_plus, std::string content) {
	this->name = name;
	this->is_equipped = is_equipped;
	this->max_health_plus = max_health_plus;
	this->max_endurance_plus = max_endurance_plus;
	this->max_strength_plus = max_strength_plus;
	this->content = content;
};

void Item::apply_perks(Character &player) {
	player.max_health += max_health_plus;
	player.current_health += max_health_plus;
	player.max_endurance += max_endurance_plus;
	player.current_endurance += max_endurance_plus;
	player.max_strength += max_strength_plus;
	player.current_strength += max_strength_plus;
};

void Item::read() {
	// if readable
	c();
	std::cout << "*\n" << content << "\n*" << std::endl;
	std::cin.ignore();
	std::cin.ignore();
	c();
}

Item release_paper("Release Paper", false, 0, 0, 0, "Letter from Garokh, The High Elf to Ariok, The Front Guard.\nI, Garokh, allow the release of Prisoner #0192.\nReason: Unknown / Unstated.\nStated exceptions to his release:\n - Assault of a Guard.\n - Theft.\n - Forged / Fake release paper.\n - Failure to comply with authority of any rank.");
Item health_ring("Health Ring", false, 5, 0, 0, "");
Item duty_paper("Prisoner #0192's Duty.", false, 0, 0, 0, "Letter from the United Councils (UC).\nYou must be surprised about your release, Prisoner #0192. For obvious reasons, I can't state as to why you were released.\nBoth the Council of Heliq and the Council of Ezrik agreed to your release, however the Council of Sover declined.\nYour Duty: Go to the town of Asora. Find our veteran spy, Fayee Storm. She'll give you further details.");
