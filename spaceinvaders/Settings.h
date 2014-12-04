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
	Settings(vector<vector<string>>);

	void changeDifficulty() ;
	string addHighScore() ;
	void saveSettings() ;
	void saveHighScore() ;

	vector<char> getKeyBindings() ;

private:
	struct singleSetting // one setting is stored in a Trio
	{
		singleSetting() ;
		singleSetting(string t, string n, string v) : type(t), name(n), value(v) {} ;
		string type;
		string name;
		string value;
	};
	vector<singleSetting> settings_map ;
	ifstream fin;
	ofstream fout;
	string configFile ;

};

#endif
