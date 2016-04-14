#include "Fireball.h"
#include "Inspector.h"

void Fireball::Move(Map& map) {
	intVector2 prev = pos;		
	if (map.map[pos.first + dir.first][pos.second + dir.second] == wall) {
		map.objects[pos.first + dir.first][pos.second + dir.second]->Collide(this);
		return;
	}
	map.objects[pos.first + dir.first][pos.second + dir.second]->Collide(this);
	Inspector::GetInstance().SwapObjects(prev, pos);
}

void Fireball::CollideWith(Pass* pass) {
	intVector2 tmp = this->pos;
	this->pos = pass->GetPos();
	pass->SetPos(tmp);	
	return;
}

void Fireball::CollideWith(Wall* wall) {	
	Inspector::GetInstance().PutObject(new Pass(intVector2(pos.first, pos.second)),
		intVector2(pos.first, pos.second));
	erase = true;	
}

void Fireball::CollideWith(Spawner* sp) {
	Inspector::GetInstance().PutObject(new Pass(intVector2(pos.first, pos.second)),
		intVector2(pos.first, pos.second));
	erase = true;
}

void Fireball::CollideWith(Monster* monster) {
	Inspector::GetInstance().PutObject(new Pass(intVector2(pos.first, pos.second)),
		intVector2(pos.first, pos.second));
	erase = true;
	monster->TakeDamage(fireballDamage);
}

void Fireball::CollideWith(Knight* knight) {
	Inspector::GetInstance().PutObject(new Pass(intVector2(pos.first, pos.second)),
		intVector2(pos.first, pos.second));
	erase = true;
	knight->TakeDamage(fireballDamage);
}

void Fireball::CollideWith(Medkit* medkit) {
	erase = true;
	medkit->erase = true;
}

void Fireball::CollideWith(Fireball* fire) {
	erase = true;
	fire->erase = true;
}