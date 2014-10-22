/*
	File Author: Charlie Mathews
	Date: 10/21/2013
	Description: Driver
*/


#include "World.h"
#include "Entity.h"
#include "Entity_Inanimate.h"
	#include "Barrier.h"
#include "Entity_Animate.h"
	#include "Player.h"
	#include "Alien.h"
	#include "Projectile.h"

#include "SpaceInvaders.h"

int main() 
{

	SpaceInvaders game("settings.config",15,20) ;
	game.runGame();

	return 0 ;
}