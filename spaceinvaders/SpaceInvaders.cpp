/*

*/

#include "SpaceInvaders.h"

SpaceInvaders::SpaceInvaders(string config, int w, int h) : GridGame(config,w,h)
{
	graphics["Alien 1"]				= "x";
	graphics["Alien 2"]				= "~";
	graphics["Projectile"]			= "*";
	graphics["Player"]				= "^";
	graphics["Barrier full"]		= "=";
	graphics["Barrier half"]		= "_";
	graphics[DEFAULT_GRID_IDENT]	= " ";
}

SpaceInvaders::~SpaceInvaders(){}

void SpaceInvaders::runGame(){
	for(;;){
		input.recieveinput();
		update();
		draw();
	}
}

void SpaceInvaders::update() // game logic
{
	// Cycle all entities in the world.
	int sizex = world.size('x') ;
	int sizey = world.size('y') ;

	for(int i = 0; i < sizex; ++i)
	{
		for(int j = 0; j < sizey; ++j)
		{
			Entity* entity = world.getEntity(Coord(i,j)) ;
			if(entity != nullptr) entity->cycle(world, *settings, input, 0) ;
		}
	}
}

void SpaceInvaders::draw() // TODO: revamp
{
	for(int i=0; i<gridHeight; i++) {
		for(int k=0; k<gridWidth*4/1.3; k++) { cout << " "; if(k==gridWidth*3) cout << endl; } // adds the spacing on top to place each entity in a 3x3 grid
		for(int j=0; j<gridWidth; j++)
			//cout << "  " << convert[temp[i][j]] << " "; // runs through the display list to print the character to the screen	
			cout << " . " ;
	}
}
