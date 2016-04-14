#include "Map.h"

Map::Map() {
	height = 0;
	width = 0;
}

Map::~Map() {
	for (auto i : map) {
		i.clear();
	}
	map.clear();
}

void Map::Read(std::string fileName) {
	std::ifstream mapIn;

	mapIn.open(fileName);
	if (!mapIn) {
		std::cout << "Map file not found" << std::endl;
		throw "Map file not found";
	}

	mapIn >> height >> width;		
	for (int i = 0; i < height; i++) {
		std::string tmp;
		mapIn >> tmp;
		map.push_back(tmp);
	}	
}

void Map::Display() const {
	for (auto i : map) {
		std::cout << i << std::endl;
	}	
}

void Map::Clear() const {	
	//system("cls");
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
}
