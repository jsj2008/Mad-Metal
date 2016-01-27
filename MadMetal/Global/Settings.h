#pragma once

#include <map>
#include <string>
#include <vector>
#include "..\Files\FileReader.h"
#include "..\Files\FileWriter.h"

class Settings
{
private:
	static std::map<std::string, std::string> settings;
public:
	Settings();
	~Settings();
	static void loadSettingsFromFile(char *fileName);
	static std::string getSetting(char *name);
	static void setSetting(char *name, char *value);
	static void storeToFile(char *name);
};
