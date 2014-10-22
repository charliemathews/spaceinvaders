/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: 
*/

#include <string>
using std::string ;

#include "Alien.h"

void Alien::cycle(World& w, Settings& s, KeyInput& i, int t)
{

}

Message Alien::react(World& world, Message m)
{
	takeHit(world, m.damage) ;
	return Message() ;
}
