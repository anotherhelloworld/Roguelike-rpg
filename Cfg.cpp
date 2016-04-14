#include "Constants.h"

Cfg& Cfg::GetInstence() {
	static Cfg cfg("Config.txt");
	return cfg;
}

Cfg::~Cfg() {
	if (file != nullptr) {
		std::fclose(file);
	}
}

int Cfg::GetVal(char* field) {
	auto a = cfg.FindMember(field);
	if (a != cfg.MemberEnd()) {
		rapidjson::Type type = cfg[field].GetType();
		if (type != rapidjson::kNumberType) {
			std::cout << field << " " << "not integer" << std::endl;
			exit(EXIT_FAILURE);
		}
		return (int)cfg[field].GetDouble();
	}
	else {
		std::cout << "Field " << field << " not found in config" << std::endl;
		exit(EXIT_FAILURE);
	}	
};

Cfg::Cfg(char* fileName) {	
	file = std::fopen(fileName, "r");
	if (!file) {		
		std::cout << "Config file 'Config.txt' not found" << std::endl;
		exit(EXIT_FAILURE);
	}
	ReadCfg();	
};

void Cfg::ReadCfg() {
	char readBuffer[65536];
	rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));
	rapidjson::ParseResult ok = cfg.ParseStream(is);
	if (!ok) {
		std::cout << "JSON parse error: " << rapidjson::GetParseError_En(ok.Code()) << std::endl;
		exit(EXIT_FAILURE);
	}
};