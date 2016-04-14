#include "Zombie.h"

std::string Zombie::HealthBar() const {
	return "Zombie: " + std::to_string(health) + "/" + std::to_string(zombieHealth); 
}

