#ifndef H_SpaceInvaders
#define H_SpaceInvaders

#include "GridGame.h"

class SpaceInvaders: public GridGame
{
public:
	SpaceInvaders();
	~SpaceInvaders();
	void runGame();

private:
	void draw();
	void updateScore(float s);
	void update();
};

#endif
