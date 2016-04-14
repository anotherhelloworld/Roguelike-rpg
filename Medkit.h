#pragma once

#include "Entity.h"

class Medkit : public Entity {
public:
	Medkit(intVector2 pos) : Entity(pos, medkit) {};
	~Medkit() {};
	void Collide(Object* obj) { obj->CollideWith(this); };
	void Move(Map& map) {};
};