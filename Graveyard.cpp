#include "Graveyard.h"
#include "Inspector.h"

void Graveyard::Spawn(Map& map) {
	if (CheckandSpawn(map, intVector2(pos.first - 1, pos.second)) ||
		CheckandSpawn(map, intVector2(pos.first + 1, pos.second)) ||
		CheckandSpawn(map, intVector2(pos.first, pos.second - 1)) ||
		CheckandSpawn(map, intVector2(pos.first, pos.second + 1))) {
		return;
	}
	stepCounter += 1;
}

bool Graveyard::CheckandSpawn(Map& map, intVector2 pos) {
	if (stepCounter < 15) {
		return false;
	}
	if (map.map[pos.first][pos.second] == pass) {
		delete map.objects[pos.first][pos.second];
		map.objects[pos.first][pos.second] = new Zombie(intVector2(pos.first, pos.second));
		map.map[pos.first][pos.second] = zombieSymbol;
		Inspector::GetInstance().PushCharacter((Zombie*)map.objects[pos.first][pos.second]);
		stepCounter = 0;
		return true;
	}
	return false;
}