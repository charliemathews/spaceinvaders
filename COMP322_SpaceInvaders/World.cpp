/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/17/2013
	Course: COMP322
	Description: A world of entities with unique game AI.
*/

#include <iostream>
using namespace std ;

#include "World.h"
#include "Entity.h"

World::World(int size_x, int size_y) : worldSize_X(size_x), worldSize_Y(size_y) { createWorld() ; } ;

World::~World()
{
	for(int i = 0 ; i < worldSize_X; ++i) {
		for(int j = 0; j < worldSize_Y; ++j) {
			delete grid[i][j] ;		
		}
		delete grid[i] ;
	}
	delete grid ;
}

void World::createWorld()
{
	grid = new Entity ** [worldSize_X] ;
	for(int i = 0 ; i < worldSize_X ; ++i) grid[i] = new Entity * [worldSize_Y] ;
	for(int i = 0 ; i < worldSize_X; ++i) { for(int j = 0; j < worldSize_Y; ++j) { grid[i][j] = nullptr ; } }
}

void World::draw() // DEBUG FUNCTION
{
	for(int j = 0; j < worldSize_Y; ++j)
	{
		for(int i = 0; i < worldSize_X; ++i)
		{
			string ident = (grid[i][j]!=nullptr) ? grid[i][j]->getIdent() : "." ;
			cout << ident << " " ;
		}
		cout << endl ;
	}
}

int World::size(char axis) { return (axis == 'x') ? worldSize_X : worldSize_Y ; }

bool World::inBounds(Coord loc)
{
	if(loc.x < worldSize_X && loc.x >= 0 && loc.y < worldSize_Y && loc.y >= 0) return true ;
	else return false ;
}

Entity* World::getEntity(Coord loc)
{
	if(!inBounds(loc)) return nullptr ;
	if(grid[loc.x][loc.y] == nullptr) return nullptr ;
	return grid[loc.x][loc.y] ; 
}

Coord* World::getCoord(Entity* toFind)
{ 
	for(int i = 0 ; i < worldSize_X; ++i) {
		for(int j = 0; j < worldSize_Y; ++j) {
			if(grid[i][j] == toFind) {
				return new Coord(i,j) ;
			}
		}
	}
	return nullptr ;
}

bool World::add(Entity* toAdd, Coord loc)
{
	if(grid[loc.x][loc.y] == nullptr && inBounds(loc)) { grid[loc.x][loc.y] = toAdd ; return true ; }
	else return false ;
}

bool World::remove(Entity* toRem)
{ 
	Coord* toRemCoord = getCoord(toRem) ;
	if(toRemCoord != nullptr)
	{
		grid[toRemCoord->x][toRemCoord->y] = nullptr ;
		return true ;
	}
	else return false ;
}

void World::move(Entity* toMove, Coord newLoc)
{
	remove(toMove) ;
	Entity* newEntityLoc = getEntity(newLoc) ;
	if(newEntityLoc != nullptr) erase(newEntityLoc) ;
	add(toMove, newLoc) ;
}

void World::erase(Entity* toErase) {
	if(toErase != nullptr) { 
		delete toErase ;
		remove(toErase) ;
	}
}