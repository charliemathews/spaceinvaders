/*

*/

#ifndef H_Settings
#define H_Settings

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

class Settings
{

public:
	Settings();
	Settings(string f) : configFile(f) {} ;

	void changeDifficulty() ;
	string addHighScore() ;
	void saveSettings() ;
	void saveHighScore() ;

	vector<char> getKeyBindings() ;

private:
	struct Trio // one setting is stored in a Trio
	{
		string type;
		string name;
		string value;
	};
	vector<Trio> settings_map ;
	ifstream fin;
	ofstream fout;
	string configFile ;

};

#endif
