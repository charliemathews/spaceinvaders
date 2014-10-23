/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: 
*/

#include <string>
#include "World.h"
#include "Projectile.h"
using std::string ;

#include "Player.h"

void Player::cycle(World& w, Settings& s, KeyInput& i, int t)
{
	// TODO: use settings to get keybindings

	if(t != timeFrame) // player can move all the time
	{
		if(i.isKeyDown('A')) motion = left ;
		else if(i.isKeyDown('D')) motion = right ;
		move(w) ;
		motion = none ;
		timeFrame = t ;
		if(i.isKeyDown(' ')){
			Coord location = *w.getCoord(this);
			location.y --;
			w.add(new Projectile(up),location);
		}// fire lazor
	}
}

Message Player::react(World& world, Message m)
{
	takeHit(world, m.damage) ;
	return Message() ;
}
