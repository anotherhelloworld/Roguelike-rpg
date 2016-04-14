#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <map>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include "rapidjson-master\include\rapidjson\document.h"
#include "rapidjson-master\include\rapidjson\writer.h"
#include "rapidjson-master\include\rapidjson\stringbuffer.h"
#include "rapidjson-master\include\rapidjson\filereadstream.h"
#include "rapidjson-master\include\rapidjson\error\error.h" 
#include "rapidjson-master\include\rapidjson\error\en.h"

class Cfg {
public:
	static Cfg& GetInstence();
	~Cfg();
	int GetVal(char* field);
private:
	FILE* file;
	rapidjson::Document cfg;
	Cfg(char* fileName);
	void ReadCfg();
	Cfg(const Cfg &);
	Cfg & operator=(const Cfg &);
};

//static rapidjson::Document ReadConfig() {
//	FILE* fp = fopen("Config.txt", "r");
//
//	char readBuffer[65536];
//	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));	
//	rapidjson::Document cfg;
//	cfg.ParseStream(is);
//	fclose(fp);	
//	return cfg;
//}
//
//const rapidjson::Document cfg = ReadConfig();
//
//static int GetVal(char* name) {
//	return cfg[name].GetInt();
//};

const int knightHealth	= Cfg::GetInstence().GetVal("knightHealth");
const int zombieHealth	= Cfg::GetInstence().GetVal("zombieHealth");
const int princessHealth= Cfg::GetInstence().GetVal("princessHealth");
const int dragonHealth	= Cfg::GetInstence().GetVal("dragonHealth");
const int wizardHealth	= Cfg::GetInstence().GetVal("wizardHealth");
const int medkitHealth	= Cfg::GetInstence().GetVal("medkitHealth");
const int maxMedkitCount= Cfg::GetInstence().GetVal("maxMedkitCount");

const int knightDamage	= Cfg::GetInstence().GetVal("knightDamage");
const int zombieDamage	= Cfg::GetInstence().GetVal("zombieDamage");
const int princessDamage= Cfg::GetInstence().GetVal("princessDamage");
const int dragonDamage	= Cfg::GetInstence().GetVal("dragonDamage");
const int wizardDamage	= Cfg::GetInstence().GetVal("wizardDamage");
const int fireballDamage= Cfg::GetInstence().GetVal("fireballDamage");

const char wall = '#';
const char pass = '.';
const char medkit = '+';
const char graveyard = '!';
const char nest = '@';
const char rightFireball = '>';
const char leftFireball = '<';
const char upFireball = '^';
const char downFireball = 'v';

const char knightSymbol	  = 'K';
const char zombieSymbol	  = 'Z';
const char princessSymbol = 'P';
const char dragonSymbol   = 'D';
const char wizardSymbol	  = 'W';

const std::string mapFile = "Map1.txt";

const std::string dieMessage = "You were killed...";
const std::string winMessage = "You saved the princess ...";

