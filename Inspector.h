#pragma once

#include "Map.h"
#include "Object.h"
#include "Character.h"
#include "Knight.h"
#include "Zombie.h"
#include "Princess.h"
#include "Dragon.h"
#include "Wall.h"
#include "Pass.h"
#include "Medkit.h"
#include "Wizard.h"
#include "Fireball.h"
#include "Spawner.h"
#include "Graveyard.h"
#include "Nest.h"
#include "intVector2.h"
#include <typeinfo>
#include <algorithm>
#include <string>
#include <memory>
#include <cmath>
#include <list>
#include <iterator>
#include <vector>

class Inspector {
public:				
	static Inspector& GetInstance();	
	void Start();	
	const Knight& GetKnight() const;
	const Princess& GetPrincess() const;
	Knight* knight;
	Princess* princess;
	std::list <Character*> characters;					
	void PutObject(Object*, intVector2);
	void ReduceMedkitCount() { *(medkitCount) = *(medkitCount) - 1; };
	void PushEntity(Entity*);
	void PushCharacter(Character*);
	void PushSpawner(Spawner*);
	void RemoveEntity(Entity*);
	void SwapObjects(intVector2, intVector2);
private:
	Inspector() { SetUp(mapFile); };
	void SetUp(std::string fileName);
	void MapDisplay();
	void NextMove();		
	void MapRead(std::string);
	void Spawn();	
	void RunSpawners();
	void medkitSpawn();
	void medkitCheck();
	void HealthDisplay() const;	
	void RemoveCorpse();
	void RemoveEntities();
	bool Lose() const;	
	bool Win() const;		
	//void ReadConfig();
	bool mapIsDisplayed = false;		
	int stepCount = 0;
	int* medkitCount = new int(0);
	Map& map = *(new Map);
	std::list <Entity*> entities;
	std::list <Spawner*> spawners;
};