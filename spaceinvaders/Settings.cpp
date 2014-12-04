/*

*/

#include <sstream>
#include <vector>
using namespace std ;

#include "Settings.h"

Settings::Settings()
{
	// default settings
	settings_map.push_back(singleSetting("keyBinding","moveLeft","A"));
	settings_map.push_back(singleSetting("keyBinding","moveRight","D"));
	settings_map.push_back(singleSetting("keyBinding","shoot"," "));
}


Settings::Settings(vector<vector<string>> settings_input)
{
	for(auto &p : settings_input)
	{
		if(p.size() == 3 && p[1] == "keybinding")
		{
			string action, key;
			stringstream ss ;
			ss << p[2] ;

			string segment;
			vector<string> seglist;

			while(getline(ss, segment, ' '))
			{
			   seglist.push_back(segment);
			}

			if(seglist.size() == 2)
			{
				// special cases
				if(seglist[1] == "space") seglist[1] = " " ;

				settings_map.push_back(singleSetting("keyBinding", seglist[0], seglist[1]));
			}
		}
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
