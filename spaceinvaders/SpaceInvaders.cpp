/*

*/

#include "SpaceInvaders.h"
#include "Entity_Animate.h"

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
	// cycle all entities in the world.
	for(int i = 0; i < gridWidth; ++i)
	{
		for(int j = 0; j < gridHeight; ++j)
		{
			Entity* entity = world.getEntity(Coord(i,j)) ;
			if(entity != nullptr) entity->cycle(world, *settings, input, 0) ;
		}
	}

	// check for endgame
	for(int i = 0; i < gridWidth; ++i)
	{
		Entity* entity = world.getEntity(Coord(i,gridHeight-4)) ; // checking the row above barriers. if alien, kill game
		if(entity != nullptr && entity->getIdent() == "alien") exit(0) ;
	}

	// set alien's direction of motion
	// TODO: eventually dynamically align the enemy movement to the grid size. For now, assume default.
	if(enemyMoveCount == 4)
	{
		setEnemiesDir(down) ;
	}
	else if(enemyMoveCount == 5)
	{
		direction newDir = (lastDir == left) ? right : left ;
		lastDir = newDir ;
		enemyMoveCount = 0 ;
		setEnemiesDir(newDir) ;
	}
	else enemyMoveCount++ ;
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

void SpaceInvaders::setEnemiesDir(direction m)
{
	for(int i = 0; i < gridWidth; ++i)
		for(int j = 0; j < gridHeight; ++j)
		{
			Entity* entity = world.getEntity(Coord(i,j)) ;
			if(entity != nullptr)
			{
				if(entity->getIdent() == "alien") entity->setDirection(m) ;
			}
		}
}