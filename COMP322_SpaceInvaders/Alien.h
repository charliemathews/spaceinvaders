/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/20/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_Alien
#define H_Alien

#include <string>
using std::string ;

#include "Entity_Animate.h"

class Alien : AnimateEntity {

public:
	Alien(int h = 1, string i = "alien") : AnimateEntity(h,i) {} ;
	void cycle(World&) ;

private:
	void move(World&) ;

};

#endif
