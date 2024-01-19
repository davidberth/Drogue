#include <string>
#include <fstream>
#include <sstream>
#include "shader.h"

using namespace std;

string read_shader_from_file(string filename) {
	ifstream ifs(filename);
	ostringstream oss;
	oss << ifs.rdbuf();
	string contents = oss.str();
	return contents;
}