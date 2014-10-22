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
	GridGame(string config = "settings.config", int w = DEFAULT_GRID_WIDTH, int h = DEFAULT_GRID_HEIGHT) ;
	~GridGame();
	virtual void runGame() = 0 ; //starts the game loop and additional setup

protected:
	virtual void draw() = 0 ;
	virtual void update() = 0 ;
	virtual void updateScore(int);

	void setWindowSize(int,int);

	int gridWidth, gridHeight ;
	Settings* settings;
	KeyInput input;
	map<string,string> graphics;
	int score ;
	int gametime; // TBD

private:
	vector<vector<string>> temp;
};

#endif