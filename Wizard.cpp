#include "Wizard.h"
#include "Inspector.h"

std::string Wizard::HealthBar() const {
	return "Wizard: " + std::to_string(health) + "/" + std::to_string(wizardHealth);
}

void Wizard::Move(Map& map) {	
	if (Cooldown) {
		Cooldown = false;
		return;
	}
	bool shot = false;
	intVector2 target = Inspector::GetInstance().GetKnight().GetPos();
	if (CheckDistance((Character&)Inspector::GetInstance().GetKnight()) == 2) {		
		return;
	}
	if (CheckDistance((Character&)Inspector::GetInstance().GetKnight()) == 1) {
		Monster::Move(map);
		return;
	}

	if (pos.first == target.first) {		
		shot = CheckHorShot(map, pos.second, target.second, intVector2(pos.first, pos.second - 1),
			intVector2(0, -1), leftFireball);	
		if (shot) { return; }
		shot = CheckHorShot(map, target.second, pos.second, intVector2(pos.first, pos.second + 1),
			intVector2(0, 1), rightFireball);
		if (shot) { return; }
	}	

	if (pos.second == target.second) {
		shot = CheckVertShot(map, pos.first, target.first, intVector2(pos.first - 1, pos.second),
			intVector2(-1, 0), upFireball);
		if (shot) { return; }
		shot = CheckVertShot(map, target.first, pos.first, intVector2(pos.first + 1, pos.second),
			intVector2(1, 0), downFireball);
		if (shot) { return; }
	}
	if (shot) { return; }
	Monster::Move(map);
}

bool Wizard::AddFireball(Map& map, intVector2 pos, intVector2 dir, char symbol) {
	if (map.map[pos.first][pos.second] != pass) {
		return false;
	}
	delete map.objects[pos.first][pos.second];
	Inspector::GetInstance().PutObject(new Fireball(intVector2(pos.first, pos.second),
		dir, symbol),
		intVector2(pos.first, pos.second));
	Inspector::GetInstance().PushEntity((Entity*)map.objects[pos.first][pos.second]);
	Cooldown = true;
	return true;
}

bool Wizard::CheckHorShot(Map& map, int left, int right, intVector2 fpos, intVector2 dir, char symbol) {		
	if (left > right) {
		for (int i = right + 1; i < left; i++) {
			if (map.map[pos.first][i] != pass) {
				if (FireballCheck(map.map[pos.first][i])) {
					continue;
				}				
				return false;				
			}
		}
		if (!AddFireball(map, fpos, dir, symbol)) {
			return false;
		}			
		return true;		
	}
	return false;
}

bool Wizard::CheckVertShot(Map& map, int left, int right, intVector2 fpos, intVector2 dir, char symbol) {	
	if (left > right) {
		for (int i = right + 1; i < left; i++) {
			if (map.map[i][pos.second] != pass) {
				if (FireballCheck(map.map[i][pos.second])) {
					continue;
				}				
				return false;				
			}
		}				
		if (!AddFireball(map, fpos, dir, symbol)) {
			return false;
		}
		return true;		
	}
	return false;
}
