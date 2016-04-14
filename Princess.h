#pragma once

#include "Character.h"
#include <map>

class Princess : public Character {
public:
	Princess(intVector2 pos) :
		Character(pos, knightHealth, princessSymbol, knightDamage) {};
	~Princess() {};
	void Move(Map&) {};
	void Collide(Object* obj) { obj->CollideWith(this); }
	void CollideWith(Wall*) {};
	void CollideWith(Pass*) {};
	void CollideWith(Knight*) {};
	void CollideWith(Monster*) {};
	void CollideWith(Fireball*) {};
	std::string HealthBar() const;	
};