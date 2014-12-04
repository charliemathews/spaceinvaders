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
	string delimiters;
	string fname;
	char sep_delim;
	char eqv_delim;
public:
	Parser(string filepath, char sep, char eqv);
	vector<vector<string>>linesMatching(string key, int pos = 0);
	vector<vector<string>>linesContaining(string key, int pos = 0);
	void deleteMatching(string key, int pos = 0);
	void deleteContaining(string key, int pos = 0);
	void add(string linetoadd);
	void saveToFile();
};

#endif