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

int main() {

	World* world = new World() ;
	world->draw() ;

	Player p1() ;

	return 0 ;
}