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

	World* world = new World(15,20) ;
	Player* thePlayer = new Player() ;

	world->add(thePlayer, Coord(0,world->size('y')-1)) ; // player always spawns in bottom left
	
	world->add(new Barrier(), Coord(1,17)) ;
	world->add(new Barrier(), Coord(4,17)) ;
	world->add(new Barrier(), Coord(7,17)) ;
	world->add(new Barrier(), Coord(10,17)) ;
	world->add(new Barrier(), Coord(13,17)) ;

	world->add(new Alien(), Coord(1,2)) ;
	world->add(new Alien(), Coord(3,2)) ;
	world->add(new Alien(), Coord(5,2)) ;
	world->add(new Alien(), Coord(7,2)) ;
	world->add(new Alien(), Coord(9,2)) ;

	world->add(new Alien(), Coord(1,4)) ;
	world->add(new Alien(), Coord(3,4)) ;
	world->add(new Alien(), Coord(5,4)) ;
	world->add(new Alien(), Coord(7,4)) ;
	world->add(new Alien(), Coord(9,4)) ; 

	world->add(new Alien(), Coord(1,6)) ;
	world->add(new Alien(), Coord(3,6)) ;
	world->add(new Alien(), Coord(5,6)) ;
	world->add(new Alien(), Coord(7,6)) ;
	world->add(new Alien(), Coord(9,6)) ; 

	world->add(new Alien(), Coord(1,8)) ;
	world->add(new Alien(), Coord(3,8)) ;
	world->add(new Alien(), Coord(5,8)) ;
	world->add(new Alien(), Coord(7,8)) ;
	world->add(new Alien(), Coord(9,8)) ; 

	world->draw() ; system("pause"); system("cls");

	for(int i = 0; i < 1; ++i)
	{
		Coord playerLoc = *world->getCoord(thePlayer) ;
		Coord newPlayerLoc = playerLoc ;
		newPlayerLoc.x += 1 ;
		world->move(thePlayer, newPlayerLoc) ;
		world->draw() ; system("pause"); system("cls");
	}

	SpaceInvaders game("settings.config",15,20) ;
	//game.runGame();

	return 0 ;
}