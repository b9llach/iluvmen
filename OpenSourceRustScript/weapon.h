#include <string>
#include <WTypesbase.h>
#include <vector>

struct vector2 {
	float x, y;
};

class weapon {
public:
	std::string cweapon = "AK47";
	std::string cscope = "NONE";
	std::string cbarrel = "NONE";

	std::vector<vector2> ctable;
	std::vector<double> ccontroltime;
	float cdelay;

	void humanized(float delay, double control_time, int x, int y);
	void blatant(float delay, double control_time, float x, float y);
	void query_sleep(int ms);
	void move_mouse(int x, int y);
	void get_info();
	float get_scope();

	float randomize(float value, int perc);
};