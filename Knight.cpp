#include "Inspector.h"

Knight::Knight(intVector2 pos): Character(pos, knightHealth, knightSymbol, knightDamage) {
	moves.insert(std::pair <char, intVector2>('w', intVector2(-1,	0)));
	moves.insert(std::pair <char, intVector2>('a', intVector2( 0,  -1)));
	moves.insert(std::pair <char, intVector2>('s', intVector2( 1,	0)));
	moves.insert(std::pair <char, intVector2>('d', intVector2( 0,	1)));
}


void Knight::Move(Map& map) {		
	char key = _getch();	

	intVector2 prev = pos;
	map.objects[pos.first + moves[key].first][pos.second + moves[key].second]->Collide(this);		
	Inspector::GetInstance().SwapObjects(prev, pos);
	map.map[pos.first][pos.second] = Symbol();
	return;
}

std::string Knight::HealthBar() const {
	return "Knight: " + std::to_string(health) + "/" + std::to_string(knightHealth);
}

void Knight::CollideWith(Pass* pass) {		
	intVector2 tmp = this->pos;
	this->pos = pass->GetPos();	
	pass->SetPos(tmp);
	return;
}

void Knight::CollideWith(Princess* pr) {
	intVector2 tmp = this->pos;
	this->pos = pr->GetPos();	
	return;
}

void Knight::CollideWith(Monster* obj) {
	obj->TakeDamage(damage);
}