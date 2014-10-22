/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/21/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_EntityA
#define H_EntityA

#include <string>
using std::string ;

#include "Entity.h"

class AnimateEntity : public Entity {

public:
	AnimateEntity(int h = DEFAULT_ENTITY_HEALTH, string i = DEFAULT_ENTITY_IDENT, int d = 0, direction m = none) : Entity(h,i,d), motion(m) {} ;
	void setDirection(direction) ;

protected:
	virtual void move(World&) ; // move in direction, if space is empty and inbounds()
	direction motion ;
};

#endif
