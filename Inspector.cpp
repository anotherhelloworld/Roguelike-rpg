#include "Inspector.h"
//#include "rapidjson-master\include\rapidjson\document.h"
//#include "rapidjson-master\include\rapidjson\writer.h"
//#include "rapidjson-master\include\rapidjson\stringbuffer.h"
//#include "rapidjson-master\include\rapidjson\filereadstream.h"

Inspector& Inspector::GetInstance() {
	static Inspector inspector;
	return inspector;
}

void Inspector::Start() {
	MapDisplay();
	while (!Lose()) {
		//MapDisplay();		
		NextMove();
		RemoveCorpse();
		RemoveEntities();
		medkitCheck();
		medkitSpawn();
		RunSpawners();
		if (Win()) {
			return;
		}
		MapDisplay();		
	}
	return;
}

const Knight& Inspector::GetKnight() const {
	return *knight;
}

const Princess& Inspector::GetPrincess() const {
	return *princess;
}

void Inspector::PutObject(Object* obj, intVector2 pos) {
	map.objects[pos.first][pos.second] = obj;
};

void Inspector::PushEntity(Entity* en) {
	entities.push_back(en);
}

void Inspector::RemoveEntity(Entity* en) {
	auto i = entities.begin();
	while (i != entities.end()) {
		if ((*i)->pos == en->pos) {
			delete *i;
			entities.erase(i++);
			break;
		}
		else {
			++i;
		}
	}
}

void Inspector::SwapObjects(intVector2 prev, intVector2 pos) {
	if (pos != prev) {
		map.map[prev.first][prev.second] = pass;
		Object* tmp = map.objects[prev.first][prev.second];
		map.objects[prev.first][prev.second] = map.objects[pos.first][pos.second];
		map.objects[pos.first][pos.second] = tmp;		
	}
}

void Inspector::SetUp(std::string fileName) {
	//ReadConfig();
	MapRead(fileName);	
	Spawn();
	map.objects.resize(map.map.size(), std::vector <Object*>(map.map[0].size(), nullptr));
	
	for (auto i : characters) {
		map.objects[i->GetPos().first][i->GetPos().second] = i;
	}

	for (auto i : entities) {
		map.objects[i->GetPos().first][i->GetPos().second] = i;
	}

	for (auto i : spawners) {
		map.objects[i->GetPos().first][i->GetPos().second] = i;
	}

	map.objects[knight->GetPos().first][knight->GetPos().second] = knight;
	map.objects[princess->GetPos().first][princess->GetPos().second] = princess;
}

void Inspector::MapDisplay() {
	map.Clear();
	map.map[knight->pos.first][knight->pos.second] = knight->Symbol();
	map.map[princess->pos.first][princess->pos.second] = princess->Symbol();
	for (auto i : characters) {
		map.map[i->pos.first][i->pos.second] = i->Symbol();
	}
	for (auto i : entities) {
		map.map[i->pos.first][i->pos.second] = i->Symbol();
	}
	for (auto i : spawners) {
		map.map[i->pos.first][i->pos.second] = i->Symbol();
	}
	map.Display();
	HealthDisplay();	
}

void Inspector::NextMove() {
	knight->Move(map);			
	for (auto i : characters) {
		i->Move(map);
	}
	//MapDisplay();
	//MapDisplay();
	for (auto i : entities) {
		if (i->erase) {
			continue;
		}
		i->Move(map);
	}
	//MapDisplay();
}

void Inspector::PushCharacter(Character* ch) {
	characters.push_back(ch);
}

void Inspector::PushSpawner(Spawner* sp) {
	spawners.push_back(sp);
}

void Inspector::MapRead(std::string fileName) {
	map.Read(fileName);
}

void Inspector::Spawn() {
	map.objects.resize(map.map.size());
	for (int i = 0; i < map.map.size(); i++) {
		map.objects[i].resize(map.map[i].size(), nullptr);
		for (int j = 0; j < map.map[i].size(); j++) {
			if (map.map[i][j] == knightSymbol) {
				knight = new Knight(intVector2(i, j));
			}
			if (map.map[i][j] == wizardSymbol) {
				PushCharacter(new Wizard(intVector2(i, j)));
			}
			if (map.map[i][j] == zombieSymbol) {				
				PushCharacter(new Zombie(intVector2(i, j)));
			}
			if (map.map[i][j] == dragonSymbol) {
				PushCharacter(new Dragon(intVector2(i, j)));
			}
			if (map.map[i][j] == princessSymbol) {
				princess = new Princess(intVector2(i, j));				
			}
			if (map.map[i][j] == wall) {				
				map.objects[i][j] = new Wall(intVector2(i, j));
			}
			if (map.map[i][j] == pass) {				
				map.objects[i][j] = new Pass(intVector2(i, j));
			}
			if (map.map[i][j] == medkit) {				
				PushEntity(new Medkit(intVector2(i, j)));
			}	
			if (map.map[i][j] == graveyard) {
				PushSpawner(new Graveyard(intVector2(i, j)));
			}
			if (map.map[i][j] == nest) {
				PushSpawner(new Nest(intVector2(i, j)));
			}
		}
	}
}

void Inspector::RunSpawners() {
	for (auto i : spawners) {
		i->Spawn(map);
	}
}

void Inspector::medkitSpawn() {
	if (*medkitCount < maxMedkitCount && stepCount == 4) {		
		int first = rand() % (map.height - 1) + 1;
		int second = rand() % (map.width - 1) + 1;
		int counter = 0;
		while (map.map[first][second] != '.' || counter < 5) {
			first = rand() % (map.height - 1) + 1;
			second = rand() % (map.width - 1) + 1;
			counter++;
		}		
		delete map.objects[first][second];		
		map.objects[first][second] = new Medkit(intVector2(first, second));
		map.map[first][second] = medkit;
		*(medkitCount) = *(medkitCount) + 1;
		PushEntity((Entity*)map.objects[first][second]);
		stepCount = 0;
	}	
}

void Inspector::medkitCheck() {
	if (*medkitCount < maxMedkitCount) {
		stepCount++;
	}
}

void Inspector::HealthDisplay() const {
	std::cout << std::endl << std::endl;
	std::cout << knight->HealthBar() << "     \n";
	princess->HealthBar();
	for (auto i : characters) {
		if (knight->CheckDistance(*i) == 1) {
			std::cout << i->HealthBar() << "       \n";
		};
	}	
	for (int i = 0; i < 3; i++) {
		std::cout << "                           " <<std::endl;
	}
}

void Inspector::RemoveCorpse() {
	auto i = characters.begin();
	while (i != characters.end()) {
		if ((*i)->health <= 0) {			
			map.objects[(*i)->pos.first][(*i)->pos.second] = new Pass(intVector2((*i)->pos.first, (*i)->pos.second));
			map.map[(*i)->pos.first][(*i)->pos.second] = pass;
			delete *i;
			characters.erase(i++);			
		}
		else {
			++i;
		}
	}	
};

void Inspector::RemoveEntities() {
	auto i = entities.begin();
	while (i != entities.end()) {
		if ((*i)->erase) {			
			map.objects[(*i)->pos.first][(*i)->pos.second] = new Pass(intVector2((*i)->pos.first, (*i)->pos.second));
			map.map[(*i)->pos.first][(*i)->pos.second] = pass;
			delete *i;
			entities.erase(i++);
		}
		else {
			++i;
		}
	}
}

bool Inspector::Lose() const {
	
	if (knight->health <= 0) {
		map.Clear();
		system("cls");
		std::cout << dieMessage << std::endl;
		return true;		
	}
	return false;
}


bool Inspector::Win() const {	
	if (knight->pos == princess->pos) {
		map.Clear();
		system("cls");
		std::cout << winMessage << std::endl;
		return true;
	}
	return false;
}

//void Inspector::ReadConfig() {
//	FILE* fp = fopen("Config.txt", "r");
//
//	char readBuffer[65536];
//	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
//
//	rapidjson::Document d;
//	d.ParseStream(is);
//	fclose(fp);
//	assert(d.HasMember("knightHealth"));
//	//int a = d["knightHealth"].GetInt();
//	/**(constants["knightHealth"]) = d["knightHealth"].GetInt();
//	*(constants["zombieHealth"]) = d["zombieHealth"].GetInt();*/
//}