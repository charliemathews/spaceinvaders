/*
	Project Author(s): Charlie Mathews, Stuart Bowman, Colin Hooper, Barry McFadden
	File Author: Charlie Mathews
	Date: 10/22/2013
	Course: COMP322
	Description: Defines structure to store a message from one entity to another.
*/

#ifndef H_Message
#define H_Message

#include <string>
using std::string ;

struct Message {
	Message() : identifier("undefined"), damage(0) {} ;
	Message(string i, int d) : identifier(i), damage(d) {} ;
	string identifier ;
	int damage ;
};

#endif
