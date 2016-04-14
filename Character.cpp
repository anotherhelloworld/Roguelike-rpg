#include "Character.h"
#include "Inspector.h"

int Character::CheckDistance(Character& ch) const {
	return sqrt(pow((pos.first - ch.pos.first), 2) + pow((pos.second - ch.pos.second), 2));
}

void Character::CollideWith(Medkit* medkit) {
	intVector2 tmp = this->pos;
	this->pos = medkit->GetPos();	
	Inspector::GetInstance().PutObject(new Pass(intVector2(tmp.first, tmp.second)), 
		intVector2(medkit->GetPos().first, medkit->GetPos().second));	
	Inspector::GetInstance().RemoveEntity(medkit);	
	Inspector::GetInstance().ReduceMedkitCount();
	if (health < maxHealth) {
		health += medkitHealth;
	}	
}

void Character::CollideWith(Fireball* fireball) {
	intVector2 tmp = this->pos;
	this->pos = fireball->GetPos();
	Inspector::GetInstance().PutObject(new Pass(intVector2(tmp.first, tmp.second)),
		intVector2(fireball->GetPos().first, fireball->GetPos().second));
	Inspector::GetInstance().RemoveEntity(fireball);	
	health -= 5;	
}