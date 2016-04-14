#include "Princess.h"

std::string Princess::HealthBar() const {
	return "Princess: " + std::to_string(health) + "/" + std::to_string(princessHealth);// + "\n";
}