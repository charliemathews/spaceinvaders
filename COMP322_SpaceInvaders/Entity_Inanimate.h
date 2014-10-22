/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/20/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_EntityIA
#define H_EntityIA

#include <string>
using std::string ;

#include "Entity.h"

class InanimateEntity : public Entity {

public:
	InanimateEntity(int h = DEFAULT_ENTITY_HEALTH, string i = DEFAULT_ENTITY_IDENT) : Entity(h,i) {} ;

};

#endif
