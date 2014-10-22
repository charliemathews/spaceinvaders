/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/20/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_EntityA
#define H_EntityA

#include <string>
using std::string ;

#include "Entity.h"

class AnimateEntity : Entity {

public:
	AnimateEntity(int h = DEFAULT_ENTITY_HEALTH, string i = DEFAULT_ENTITY_IDENT) : Entity(h,i), motion(none) {} ;

private:
	enum direction { up, left, down, right, none } ;
	direction motion ;
	virtual void move(World&) = 0; // move in direction, if space is empty and inbounds()

};

#endif
