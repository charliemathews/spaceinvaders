/*
	File Author: Charlie Mathews
	Date: 10/21/2013
	Description: Driver
*/


#include "World.h"
#include "Entity.h"

int main() {

	World* world = new World() ;

	world->draw() ; // just output the empty world.

	return 0 ;
}