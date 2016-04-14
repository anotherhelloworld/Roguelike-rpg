#pragma once

#include "Entity.h"
#include "Map.h"

class Fireball : public Entity {
public: 
	Fireball(intVector2 pos, intVector2 dir, char symbol) : dir(dir) ,Entity(pos, symbol) {};
	~Fireball() {};
	void Collide(Object* obj) { obj->CollideWith(this); };
	void CollideWith(Knight*);
	void CollideWith(Monster*);
	void CollideWith(Medkit*);
	void CollideWith(Fireball*);
	void CollideWith(Pass*);
	void CollideWith(Wall*);
	void CollideWith(Spawner*);
	void Move(Map& map);
private:
	intVector2 dir;
};