#pragma once

#include "Monster.h"
#include "Constants.h"

class Dragon : public Monster {
public:
	Dragon(intVector2 pos) : 
		Monster(pos, dragonHealth, dragonSymbol, dragonDamage) {};
	~Dragon() {};
	std::string HealthBar() const;
};