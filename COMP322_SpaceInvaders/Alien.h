/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_Alien
#define H_Alien

#include <string>
using std::string ;

#include "Entity_Animate.h"

class Alien : public AnimateEntity {

public:
	Alien(int h = 1, string i = "alien") : AnimateEntity(h,i,0) {} ;
	void cycle(World&) ;
	Message react(World&, Message) ;

};

#endif
