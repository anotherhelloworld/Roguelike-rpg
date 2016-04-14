#pragma once

#include "Map.h"
//#include "Constants.h"
#include "Object.h"
#include <cmath>

class Character : public Object {
	friend class Inspector;
public:
	Character(intVector2 pos, int health, char symbol, int damage) : 
		Object(pos, symbol), health(health), damage(damage), maxHealth(health) {};
	virtual ~Character() {};
	virtual void Move(Map& map) = 0;
	virtual std::string HealthBar() const = 0;
	virtual char Symbol() const { return symbol; };
	void TakeDamage(int damage) { health -= damage; };
	int CheckDistance(Character&) const;				
	void CollideWith(Medkit*);
	void CollideWith(Fireball*);
	void CollideWith(Spawner*) {};
	void CollideWith(Princess*) {};
protected:			
	bool flag = false;
	int health;
	int damage;		
	int maxHealth;
};