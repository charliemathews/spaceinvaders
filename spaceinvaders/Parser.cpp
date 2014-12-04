#include "parser.h"

Parser::Parser(string filepath, string d){
	fname = filepath;
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
		if (lines.at(i).at(pos)==key){
			lines.erase(lines.begin() + i);
			i--;//vector size has changed, we need to evaluate what's now in this spot
		}
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

void Parser::saveToFile(){
	ofstream file;
	file.open(fname);
	for (int i=0;i<lines.size();i++){
		for (int j=0;j<lines.at(i).size()-1;j++){
			file << lines.at(i).at(j);
			if (j!=lines.at(i).size()-2)//if it's not the last key element, output operator
				file<<delim.at(0);
		}
		file << delim.at(1);
		file << lines.at(i).at(lines.at(i).size()-1);//outputs the result delimeter followed by the last element
		file << endl;
	}
	file.close();
}
