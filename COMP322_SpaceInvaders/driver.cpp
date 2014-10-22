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

void setup(World* world)
{
	world = new World(15,20) ;
	
	world->add(new Player(), Coord(0,world->getSize('y')-1)) ;
}

int main() 
{

	World* world ;
	setup(world) ;

	Player p1() ;

	return 0 ;
}