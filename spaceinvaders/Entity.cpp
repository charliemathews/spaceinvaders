/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/17/2013
	Course: COMP322
	Description: Master class definition for all entities.
*/

#include <string>
using std::string ;

#include "Entity.h"
#include "World.h"

string Entity::getIdent() { return identifier ; }

void Entity::takeHit(World& world, int damage)
{
	health -= damage ;
	if(health <= 0) world.erase(this) ;
}

int Entity::getHealth() { return health ; }