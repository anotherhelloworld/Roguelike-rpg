#pragma once

#include "Entity.h"

class Spawner : public Entity {
	friend class Inspector;
public:
	Spawner(intVector2 pos, char symbol) : Entity(pos, symbol) {};
	virtual ~Spawner() {};
	void Collide(Object* obj) { obj->CollideWith(this); };
	virtual void Move(Map&) {};	
	virtual void Spawn(Map&) = 0;
protected:
	int stepCounter = 0;
};