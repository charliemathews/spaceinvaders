/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/20/2013
	Course: COMP322
	Description: 
*/

#include <string>
using std::string ;

#include "Entity_Animate.h"
#include "World.h"

void AnimateEntity::move(World& world)
{
	if(motion != none)
	{
		Coord location = *world.getCoord(this) ;
		Coord destination = location ;

		if(motion == up) destination.y -= 1;
		else if(motion == left) destination.x -= 1 ;
		else if(motion == down) destination.y += 1 ;
		else if(motion == right) destination.x += 1 ;

		if(world.inBounds(destination))
		{
			Entity* destination_owner = world.getEntity(destination) ;
			if(destination_owner != nullptr) // if entity in spot, call entity::react() ;
			{
				Message result = destination_owner->react(world, Message(identifier, damageDealt)) ;	
				if(result.damage > 0) takeHit(world,result.damage) ;
			}

			// check to see if destination_owner is still alive, if it is, die()
			if(world.getEntity(destination) == nullptr) world.erase(this) ;
			else world.move(this,destination) ;
		}
	}
}