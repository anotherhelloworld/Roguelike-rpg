#pragma once

#include "Spawner.h"

class Nest : public Spawner {
public:
	Nest(intVector2 pos) : Spawner(pos, nest) {};
	~Nest() {};
	void Spawn(Map&);
private:
	bool CheckandSpawn(Map&, intVector2);
};