/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: 
*/

#include <string>
using std::string ;

#include "Player.h"

void Player::cycle(World& world)
{
	// call move() if timing is right
	// aka every animated entity should only move if it's their turn
}

Message Player::react(World& world, Message m)
{
	takeHit(world, m.damage) ;
	return Message() ;
}