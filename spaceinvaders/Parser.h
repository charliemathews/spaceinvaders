#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Parser{
private:
	vector<vector<string>> lines;
	vector<char> delimiters;
	string delim;
public:
	Parser(string filepath, string d);
	vector<vector<string>>linesMatching(string key, int pos = 0);
	void deleteMatching(string key, int pos = 0);
	void add(string linetoadd);
};

#endif