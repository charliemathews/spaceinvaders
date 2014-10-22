/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/17/2013
	Course: COMP322
	Description: Defines structure to store a single coordinate.
*/

#ifndef H_Coordinate
#define H_Coordinate

struct Coord {
	Coord() : x(0), y(0) {} ;
	Coord(int x, int y) : x(x), y(y) {} ;
	int x ;
	int y ;
};

#endif
