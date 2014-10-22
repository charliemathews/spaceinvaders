#ifndef GRIDGAME_H
#define GRIDGAME_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <Windows.h>
#include "constants.h"
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

#include "keyinput.h"

class GridGame{
public:
	GridGame();
	~GridGame();
	settings mysettings;
	keyinput keyboardinput;
	void rungame();//starts the game loop and additional setup
protected:
	int gametime; // TBD
	virtual void update();
	virtual void updateScore(int s);
	virtual void draw();
	void setWindowSize(int,int);

private:
	vector<vector<string>> temp;
	map<string, string> convert;
};

#endif