#pragma once

#include "Entity.h"

class Pass : public Entity {
public:
	Pass(intVector2 pos) : Entity(pos, pass) {};
	void Collide(Object* obj) { obj->CollideWith(this);	};
	void Move(Map& map) {};
};