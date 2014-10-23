/*

*/

#include <sstream>
using std::stringstream ;
#include <vector>
using std::vector ;

#include "Settings.h"

Settings::Settings()
{
	// settings_map.push_back(singleSetting());
	settings_map.push_back(singleSetting("keyBinding","moveLeft","a"));
	settings_map.push_back(singleSetting("keyBinding","moveRight","d"));
	settings_map.push_back(singleSetting("keyBinding","shoot"," "));
}

Settings::Settings(string config)
{
	configFile = config ;
	fin.open(configFile);

	char test;
	bool done = false;
	while(!fin.eof())
	{
		bool foundInput = false;
		test = fin.get();
		while(!foundInput)
		{
			if(test == '/' || test == ' ' || test == '\n')
			{
				fin.putback(test);
				bool newLine = false;
				while(!newLine)
				{
					test = fin.get();
					if(test == '\n')
						newLine = true;
				}
				test = fin.get();
			}
			else
			{
				fin.putback(test);
				foundInput = true;
			}
		}
		bool endLeft = false;
		string left;
		while(!endLeft)
		{
			test = fin.get();
			if(test == '.')
				endLeft = true;
			else
				left+= test;
		}
		bool endMiddle = false;
		string middle;
		while(!endMiddle)
		{
			test = fin.get();
			if(test == ' ' || test == '=')
				endMiddle = true;
			else
				middle+= test;
		}
		bool atRight = false;
		string right;
		while(!atRight)
		{
			test = fin.get();
			if((test != ' ' && test != '=') || test == '\'')
				atRight = true;
		}
		if(test == '\'')
		{
			bool endRight = false;
			while(!endRight)
			{
				test = fin.get();
				if(test == '\'')
					endRight = true;
				else
					right+= test;
			}
		}
		else
		{
			fin.putback(test);
			bool endRight = false;
			while(!endRight)
			{
				test = fin.get();
				if(test == ' ' || test == '\'' || test == '/' || test == '\n')
					endRight = true;
				else
					right+= test;
			}
		}
		fin.putback(test);
		bool endLine = false;
		while(!endLine)
		{
			test = fin.get();
			if(test == '\n')
				endLine = true;
		}
		singleSetting input;
		input.type = left;
		input.name = middle;
		input.value = right;
		settings_map.push_back(input);
	}
}

vector<char> Settings::getKeyBindings()
{
	vector<char> output ;
	for(auto &s : settings_map)
	{
		if(s.type == "keyBinding") 
		{
			stringstream ss ;
			ss << s.value ;
			char c ;
			ss.get(c) ;
			output.push_back(c) ;
		}
	}
	return output ;
}
