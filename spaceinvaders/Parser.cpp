#include "Parser.h"

Parser::Parser(string filepath, string d){
	delim = d;
	ifstream file;
	file.open(filepath);
	string templine;
	if (file.is_open()){
		while(getline(file,templine)){
			vector<string> line;
			char str[500];
			strcpy(str,templine.c_str());
			char * ptr = strtok(str, delim.c_str());
			while(ptr !=nullptr){
				line.push_back(std::string(ptr));
				ptr = strtok(NULL,delim.c_str());
			}
			if (line.size()!=0)
				lines.push_back(line);
		}
		file.close();
	}
}

vector<vector<string>> Parser::linesMatching(string key, int pos){
	vector<vector<string>> returnvec;
	for (int i=0;i<lines.size();i++){
		if (lines.at(i).at(pos)==key)
			returnvec.push_back(lines.at(i));
	}
	return returnvec;
}

void Parser::deleteMatching(string key, int pos){
	for (int i=0;i<lines.size();i++){
		if (lines.at(i).at(pos)==key)
			lines.erase(lines.begin() + i);
	}
}

void Parser::add(string linetoadd){
	vector<string> line;
	char str[500];
	strcpy(str,linetoadd.c_str());
	char * ptr = strtok(str, delim.c_str());
	while(ptr !=nullptr){
		line.push_back(std::string(ptr));
		ptr = strtok(NULL,delim.c_str());
	}
	if (line.size()!=0)
		lines.push_back(line);
}
