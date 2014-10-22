#ifndef GRIDGAME_H
#define GRIDGAME_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <Windows.h>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

#include "Constants.h"
#include "KeyInput.h"

class GridGame{
public:
	GridGame();
	~GridGame();
	virtual void runGame() = 0 ; //starts the game loop and additional setup

protected:
	Settings settings;
	KeyInput input;
	map<string,string> graphics;

	int gametime; // TBD

	virtual void update();
	virtual void updateScore(int s);
	virtual void draw() = 0 ;

	void setWindowSize(int,int);

private:
	vector<vector<string>> temp;
};

#endif