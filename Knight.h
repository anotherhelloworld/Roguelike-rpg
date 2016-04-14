#pragma once

#include "Character.h"
#include <conio.h>
#include <map>

class Knight : public Character {
	friend class Inspector;
public:
	Knight(intVector2);	
	~Knight() { moves.clear(); };
	void Move(Map&); 
	void Damage() const;	
	std::string HealthBar() const;
	void Collide(Object* obj) {	obj->CollideWith(this); };
	void CollideWith(Wall*) {};
	void CollideWith(Pass*);
	void CollideWith(Princess*);
	void CollideWith(Knight*) {};	
	void CollideWith(Monster* obj);
private:			
	bool CheckCell(Map&, intVector2) const;		
	std::map <char, intVector2> moves;
};