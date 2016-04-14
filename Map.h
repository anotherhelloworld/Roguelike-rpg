#pragma once

//#include "Constants.h"
#include "Object.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h> //for fast console redraw


class Map {
	friend class Inspector;
public:	
	Map();
	~Map();
	void Read(std::string);
	void Display() const;	
	int height;
	int width;
	std::vector <std::string> map;
	std::vector <std::vector <Object*>> objects;
private:	
	void Clear() const;				
};