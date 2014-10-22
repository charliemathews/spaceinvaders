#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

struct Settings
{
	Settings();

	void changeDifficulty() {};
	string addHighScore() {};
	void saveSettings() {};
	void saveHighScore() {};

	struct Trio //for holding data in a trio
	{
		string type;
		string name;
		string value;
	};
	vector<Trio> data;

	//input file
	ifstream fin;
	ofstream fout;

};