#pragma once
#include <string>

class Character; // Forward declaration

class Item {
public:
	std::string name;
	bool is_equipped;
	int max_health_plus;
	int max_endurance_plus;
	int max_strength_plus;
	std::string content;
	

	Item(std::string name, bool is_equipped, int max_health_plus, int max_endurance_plus, int max_strength_plus, std::string content);

	void apply_perks(Character &player);
	void read();
};



extern Item release_paper;
extern Item health_ring;
extern Item duty_paper;
