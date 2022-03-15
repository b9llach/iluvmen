#include <iostream>
#include <map>
#include <filesystem>
#include <fstream>

class config {
public:
	std::map<std::string, float> settings;

	int load_config(std::string file_path);
	int save_config(std::string file_path, std::map<std::string, int> settings);
};