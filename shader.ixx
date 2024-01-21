module;

#include <string>
#include <fstream>
#include <sstream>

export module shader;

using namespace std;

export string read_shader_from_file(string filename) {
	ifstream ifs(filename);
	ostringstream oss;
	oss << ifs.rdbuf();
	string contents = oss.str();
	return contents;
}