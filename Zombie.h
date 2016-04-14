#pragma once

#include "Monster.h"
//#include "Constants.h"

class Zombie : public Monster {
public:
	Zombie(intVector2 pos) :
		Monster(pos, zombieHealth, zombieSymbol, zombieDamage) {};
	~Zombie() {};
	std::string HealthBar() const;
};