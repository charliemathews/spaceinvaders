#ifndef H_SpaceInvaders
#define H_SpaceInvaders

#include <string>
using std::string ;

#include "GridGame.h"
#include "Entity.h"

class SpaceInvaders: public GridGame
{
public:
	SpaceInvaders(string config = "settings.config", int w = DEFAULT_GRID_WIDTH, int h = DEFAULT_GRID_HEIGHT) ;
	~SpaceInvaders();
	void runGame();

private:
	void draw();
	void update();
};

#endif
