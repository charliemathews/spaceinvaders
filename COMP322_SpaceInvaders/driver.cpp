/*
	File Author: Charlie Mathews
	Date: 10/21/2013
	Description: Driver
*/


#include "World.h"
#include "Entity.h"

#include "Entity_Inanimate.h"
#include "Entity_Animate.h"

#include "Player.h"

int main() 
{

	World* world = new World(15,20) ;
	
	world->add(new Player(), Coord(0,world->getSize('y')-1)) ; 
	// x and y are flipped atm
	// fix this by rethinking the world calls
	// this happened because doodlebug (which this is modeled after) didn't have x and y, just size

	world->draw() ;

	system("pause");

	return 0 ;
}