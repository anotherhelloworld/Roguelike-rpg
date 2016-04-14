#include "Nest.h"
#include "Inspector.h"

void Nest::Spawn(Map& map) {
	if (CheckandSpawn(map, intVector2(pos.first - 1, pos.second)) ||
		CheckandSpawn(map, intVector2(pos.first + 1, pos.second)) ||
		CheckandSpawn(map, intVector2(pos.first, pos.second - 1)) ||
		CheckandSpawn(map, intVector2(pos.first, pos.second + 1))) {
		return;
	}
	stepCounter += 1;
}

bool Nest::CheckandSpawn(Map& map, intVector2 pos) {
	if (stepCounter < 30) {
		return false;
	}
	if (map.map[pos.first][pos.second] == pass) {
		delete map.objects[pos.first][pos.second];
		map.objects[pos.first][pos.second] = new Dragon(intVector2(pos.first, pos.second));
		map.map[pos.first][pos.second] = dragonSymbol;
		Inspector::GetInstance().PushCharacter((Dragon*)map.objects[pos.first][pos.second]);
		stepCounter = 0;
		return true;
	}
	return false;
}