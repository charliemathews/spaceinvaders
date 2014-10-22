/*
*/

#ifndef H_Entity
#define H_Entity

#include "Coordinate.h"
class World ;//#include "World.h"

class Entity {

public:
	Entity() ;
	char show() ;
	int showColor() ;
	bool checkAdj(Coord&, World&, bool) ; // is this necessary if the world is passed in?

	virtual void Move(World&) ;
	virtual void Simulate(World&) = 0 ;
	bool Spawn(Entity*, Coord, World&);

	virtual void takeHit() = 0 ;
	virtual string getIdent() ;

private:
	string identifier ;
	int spawnTime ;
	int timeFrame ;
	char displaySymbol ;
	int displayColor ;

	virtual void die() = 0 ;
};

#endif
