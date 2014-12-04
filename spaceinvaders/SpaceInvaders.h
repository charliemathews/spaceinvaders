#ifndef H_SpaceInvaders
#define H_SpaceInvaders

#include <string>
using std::string ;

#include "Parser.h"
#include <sstream>

#include "GridGame.h"
#include "Entity.h"

class SpaceInvaders: public GridGame
{
public:
	SpaceInvaders(string config = "settings.config") ;
	~SpaceInvaders();
	void runGame();

private:
	void draw();
	void update();

	int enemyMoveCount ;
	direction lastDir ;
	void setEnemiesDir(direction) ;

	void editorReadFile();
	void editorDrawGrid();
	void editorDrawSettings();
	void editorAdd();
	void editorDelete();

	vector<vector<string>> settingsEditor;
	vector<vector<string>> barrierEditor;
	vector<vector<string>> alienEditor;

	bool change_horizontal_direction ;
	bool leftAlert ;
	bool rightAlert ;

};

#endif
