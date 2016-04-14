#include "Inspector.h"
#include "Knight.h"
#include <iostream>

int main() {					
	Inspector::GetInstance().Start();
	system("pause");
	return 0;
}


/*#define _CRT_SECURE_NO_WARNINGS


#include "rapidjson-master\include\rapidjson\document.h"
#include "rapidjson-master\include\rapidjson\writer.h"
#include "rapidjson-master\include\rapidjson\stringbuffer.h"
#include "rapidjson-master\include\rapidjson\filereadstream.h"
#include <iostream>
//#include <cassert>

using namespace rapidjson;

int main() {
	FILE* fp = fopen("Config.txt", "r");

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document d;
	d.ParseStream(is);
	fclose(fp);
	assert(d.HasMember("knightHealth"));
	int a = d["knightHealth"].GetInt();
	return 0;
}*/