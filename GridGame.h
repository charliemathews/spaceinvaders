#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "keyinput.h"

class GridGame{
public:
	GridGame();
	~GridGame();
	settings mysettings;
	keyinput keyboardinput;
	void rungame();//starts the game loop and additional setup
protected:
	int gametime;
	virtual void draw();
	virtual void update();
	virtual void updateScore(int s);
};

#endif