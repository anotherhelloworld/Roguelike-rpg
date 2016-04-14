#pragma once

#include "Object.h"
#include "Map.h"

class Entity : public Object {
	friend class Inspector;
public:
	Entity(intVector2 pos, char symbol) : Object(pos, symbol) {};
	virtual ~Entity() {};
	bool erase = false;
private:
	virtual void Collide(Object*) = 0;
	virtual void CollideWith(Wall*) {};
	virtual void CollideWith(Pass*) {};
	virtual void CollideWith(Knight*) {};
	virtual void CollideWith(Monster*) {};
	virtual void CollideWith(Medkit*) {};
	virtual void CollideWith(Fireball*) {};
	virtual void CollideWith(Spawner*) {};
	void CollideWith(Princess*) {};
	virtual void Move(Map& map) = 0;	
};