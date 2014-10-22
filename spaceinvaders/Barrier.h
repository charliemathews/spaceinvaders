/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_Barrier
#define H_Barrier

#include <string>
using std::string ;

#include "Entity_Inanimate.h"

class Barrier : public InanimateEntity {

public:
	Barrier(int h = 1, string i = "barrier") : InanimateEntity(h,i) {} ;
	void cycle(World&, Settings&, KeyInput&, int) ;
	Message react(World&, Message) ;

};

#endif
