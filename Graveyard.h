#pragma once

#include "Spawner.h"

class Graveyard : public Spawner {
public:
	Graveyard(intVector2 pos) : Spawner(pos, graveyard) {};
	~Graveyard() {};
	void Spawn(Map&);
private:
	bool CheckandSpawn(Map&, intVector2);
};