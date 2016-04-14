#pragma once

#include "Entity.h"

class Wall : public Entity {
public:
	Wall(intVector2 pos) : Entity(pos, wall) {};
	void Collide(Object* obj) {	obj->CollideWith(this); };
	void Move(Map& map) {};
};