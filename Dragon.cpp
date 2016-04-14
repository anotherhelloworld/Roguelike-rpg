#include "Dragon.h"

std::string Dragon::HealthBar() const {
	return "Dragon: " + std::to_string(health) + "/" + std::to_string(dragonHealth);// +"\n";
}
