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

#include "Constants.h"
#include "Coordinate.h"
#include "EntityMessage.h"
#include "Settings.h"
#include "KeyInput.h"
class World ; // because entity and world include eachother

class Entity {

public:
	Entity(int h = DEFAULT_ENTITY_HEALTH, string i = DEFAULT_ENTITY_IDENT, int d = 0, direction m = none) : health(h), identifier(i), damageDealt(d), motion(m) {} ; // derived classes should call this constructor Animate::Animate() : Entity(int,string) {} ;
	virtual string getIdent() ;
	int getHealth() ;
	direction getMotion() ;
	void takeHit(World& world, int damage = 1) ;
	virtual void cycle(World&, Settings&, KeyInput&, int) = 0 ;
	virtual Message react(World&, Message) = 0 ;
	virtual void setDirection(direction) ;

private:
	int health ;

protected:
	string identifier ;
	int damageDealt ;
	direction motion ;
	int timeFrame ;

};

#endif
