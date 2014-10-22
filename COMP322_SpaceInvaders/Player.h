/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_Player
#define H_Player

#include <string>
using std::string ;

#include "Entity_Animate.h"

class Player : public AnimateEntity {

public:
	Player(int h = 1, string i = "player") : AnimateEntity(h,i,0) {} ;
	void cycle(World&) ;
	Message react(World&, Message) ;

};

#endif
