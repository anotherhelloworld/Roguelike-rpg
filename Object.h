#pragma once

#include "Constants.h"
#include "intVector2.h"
#include <utility>

class Object;
class Character;
class Pass;
class Wall;
class Monster;
class Knight;
class Medkit;
class Fireball;
class Character;
class Spawner;
class Princess;

class Object {	
	friend class Inspector;
public:
	Object(intVector2 pos, char symbol) : pos(pos), symbol(symbol) {};
	virtual ~Object() {};
	virtual char Symbol() { return symbol; };	
	virtual void Collide(Object*) = 0;
	virtual void CollideWith(Wall*) = 0;
	virtual void CollideWith(Pass*) = 0;
	virtual void CollideWith(Knight*) = 0;		
	virtual void CollideWith(Monster*) = 0;
	virtual void CollideWith(Medkit*) = 0;
	virtual void CollideWith(Fireball*) = 0;
	virtual void CollideWith(Spawner*) = 0;
	virtual void CollideWith(Princess*) = 0;	
	intVector2 GetPos() const { return pos; };
	void SetPos(intVector2 newPos) { pos = newPos; }
protected:
	intVector2 pos;
	char symbol;
};

