/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: 
*/

#include <string>
using std::string ;

#include "Projectile.h"
#include "World.h"

void Projectile::cycle(World& w, Settings& s, KeyInput& i, int t)
{
	if(true) // check if time is right for move
	{
		move(w) ;
	}
}

void Projectile::move(World& world)
{
	if(motion != none)
	{
		Coord location = *world.getCoord(this) ;
		Coord destination = location ;

		if(motion == up) destination.y -= 1;
		else if(motion == left) destination.x -= 1 ;
		else if(motion == down) destination.y += 1 ;
		else if(motion == right) destination.x += 1 ;

		if(!world.inBounds(destination)) world.erase(this) ;
		else AnimateEntity::move(world) ;
	}
}

Message Projectile::react(World& world, Message m)
{
	takeHit(world, m.damage) ;
	return Message() ;
}
