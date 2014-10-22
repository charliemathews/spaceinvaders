/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/20/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_Projectile
#define H_Projectile

#include <string>
using std::string ;

#include "Entity_Animate.h"

class Projectile : public AnimateEntity {

public:
	Projectile(int h = 1, string i = "projectile", int d = 1) : AnimateEntity(h,i,d) {} ;
	void cycle(World&) ;

private:
	void move(World&) ;

};

#endif
