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

void Player::cycle(World& w, Settings& s, KeyInput& i, int t)
{
	// TODO: use settings to get keybindings

	if(true) // check if time is right for move
	{
		if(i.isKeyDown('a')) motion = left ;
		else if(i.isKeyDown('d')) motion = right ;
		move(w) ;
		if(i.isKeyDown(' ')) true ; // fire lazor
	}
}

Message Player::react(World& world, Message m)
{
	takeHit(world, m.damage) ;
	return Message() ;
}
