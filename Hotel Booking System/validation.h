
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


bool fexists(string fname) {
	ifstream f;
	f.open(fname);

	bool a = f.is_open();

	f.close();
	return a;
}