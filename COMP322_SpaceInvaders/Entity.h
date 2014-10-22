/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/17/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_Entity
#define H_Entity

#include <string>
using std::string ;

#include "Coordinate.h"
class World ; // because entity and world include eachother

class Entity {

public:
	Entity(int h = 1, string i = "undefined") : health(h), identifier(i) {} ; // derived classes should call this constructor Animate::Animate() : Entity(int,string) {} ;

	virtual string getIdent() ;
	int getHealth() ;

	virtual void cycle(World&) = 0 ;
	void takeHit(World& world, int damage = 1) ;

	//virtual void Move(World&) = 0 ; // animated only - move in direction, if space is empty and inbounds()

private:
	string identifier ;
	int health ;

	//enum direction { up, left, down, right, none } ;
	//direction motion ; // animate object only
	//virtual void Move(World&) = 0; // animate object only
};

#endif
