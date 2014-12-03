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
#include "Settings.h"
#include "World.h"

class GridGame{
public:
	GridGame(string config = "settings.config") ;
	~GridGame();
	virtual void runGame() = 0 ; //starts the game loop and additional setup


protected:
	virtual void draw() = 0 ;
	virtual void update() = 0 ;

	void setWindowSize(int,int);

	int gridWidth, gridHeight ;
	Settings* settings;
	KeyInput input;
	map<string,string> graphics;
	World* world;
	int gametime;
	int score ;

	enum mode { MENU,PLAY,EDIT,HIGHSCORES };
	mode gamestate ;  

	struct coreReference {
		World* w ;
		int* score ;
	};
};

#endif