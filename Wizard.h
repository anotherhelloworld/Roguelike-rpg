#pragma once

#include "Monster.h"

class Wizard : public Monster {
public:
	Wizard(intVector2 pos) : Monster(pos, wizardHealth, wizardSymbol, wizardDamage) {};
	~Wizard() {};
	void Move(Map& map);
	std::string HealthBar() const;	
private:
	bool AddFireball(Map&, intVector2, intVector2, char);
	bool CheckVertShot(Map&, int, int, intVector2,intVector2, char);
	bool CheckHorShot(Map&, int, int, intVector2, intVector2, char);
	bool Cooldown = false;
};