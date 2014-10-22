/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/17/2013
	Course: COMP322
	Description: See *.cpp
*/

#ifndef H_World
#define H_World

#include "Coordinate.h"
class Entity ; // because entity and world include eachother

class World {

public:
	World(int size_x = 15, int size_y = 20) ;
	~World() ;

	void draw() ; // DEBUG FUNCTION

	int getSize(char) ;
	bool inBounds(Coord) ;
	Entity* getEntity(Coord) ;
	Coord* getCoord(Entity*) ;

	bool add(Entity*, Coord) ;
	bool remove(Entity*) ;
	void move(Entity*, Coord) ; // this function has no checks. It moves any entity into any requested coordinate.
	void erase(Entity*) ;

	// IDEAS
		// void cycleAll() ; // do this inside class game instead
		// Draw function can call getSize(x and y) then loop through world calling World::getEntity(Coord(i,j))->getIdent() and output accordingly

	//int getPlayerHealth() ;

private:
	int worldSize_X, worldSize_Y ;
	Entity *** grid ;
	void createWorld() ;

	//Entity* player ;
};

#endif
