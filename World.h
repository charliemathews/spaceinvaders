/*

*/

#ifndef H_World
#define H_World

#include "Coordinate.h"
class Entity ; //#include "Entity.h"

class World {

public:
	World(int,int) ;
	~World() ;
	void draw() ;
	int getSize() ;
	int getTime() ;
	bool add(Entitiy*, Coord) ;
	Entitiy* get(Coord) ;
	Coord getPoint(Entitiy*) ;
	Coord randPoint(bool) ;
	void increaseTimeFrame() ;
	bool inBounds(Coord) ;
	void move(Entitiy*, Coord) ;
	void takeDamage(Entitiy*) ;
	void kill(Entitiy*) ;
	bool remove(Entitiy*) ; // an entity should only be able to call this on itself
	int getPlayerHealth() ;

private:
	int worldSize_X, worldSize_Y ;
	int worldTimeFrame ;
	Entitiy *** grid ;
	void createWorld() ;

	Entity* player ;

};

#endif
