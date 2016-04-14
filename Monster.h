#pragma once

#include "Character.h"

#include <queue>

class Monster : public Character {
	friend class Inspector;
public:
	Monster(intVector2 pos, int health, char symbol, int damage) :
		Character(pos, health, symbol, damage) {};
	virtual ~Monster() {};
	void Move(Map&);
	bool Damage() const;	
	void Collide(Object* obj) { obj->CollideWith(this);	};
	void CollideWith(Wall*) {};
	void CollideWith(Pass*);
	void CollideWith(Knight* obj);
	void CollideWith(Monster*) {};	
protected:
	bool FireballCheck(char);
	bool FindPath(intVector2 a, intVector2 b, Map& map, std::vector <intVector2>& path) const;		
};

