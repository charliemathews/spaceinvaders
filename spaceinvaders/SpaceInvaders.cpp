/*

*/

#include <Windows.h>
using namespace std ;

#include "SpaceInvaders.h"
#include "Player.h"
#include "Barrier.h"
#include "Projectile.h"
#include "Alien.h"
#include "Entity_Animate.h"

SpaceInvaders::SpaceInvaders(string config) : GridGame(config)
{
	SetConsoleTitle(TEXT("Space Invaders"));

	graphics["player"]				= "^";
	graphics["alien"]				= "V";
	graphics["projectile"]			= "*";
	graphics["barrier"]				= "=";
	graphics[DEFAULT_GRID_IDENT]	= " ";

	Player* thePlayer = new Player() ;

	world->add(thePlayer, Coord(0,(int)world->size('y')-1)) ; // player always spawns in bottom left
	
	world->add(new Barrier(), Coord(1,17)) ;
	world->add(new Barrier(), Coord(4,17)) ;
	world->add(new Barrier(), Coord(7,17)) ;
	world->add(new Barrier(), Coord(10,17)) ;
	world->add(new Barrier(), Coord(13,17)) ;

	world->add(new Alien(), Coord(1,2)) ;
	world->add(new Alien(), Coord(3,2)) ;
	world->add(new Alien(), Coord(5,2)) ;
	world->add(new Alien(), Coord(7,2)) ;
	world->add(new Alien(), Coord(9,2)) ;

	world->add(new Alien(), Coord(1,4)) ;
	world->add(new Alien(), Coord(3,4)) ;
	world->add(new Alien(), Coord(5,4)) ;
	world->add(new Alien(), Coord(7,4)) ;
	world->add(new Alien(), Coord(9,4)) ; 

	world->add(new Alien(), Coord(1,6)) ;
	world->add(new Alien(), Coord(3,6)) ;
	world->add(new Alien(), Coord(5,6)) ;
	world->add(new Alien(), Coord(7,6)) ;
	world->add(new Alien(), Coord(9,6)) ; 

	world->add(new Alien(), Coord(1,8)) ;
	world->add(new Alien(), Coord(3,8)) ;
	world->add(new Alien(), Coord(5,8)) ;
	world->add(new Alien(), Coord(7,8)) ;
	world->add(new Alien(), Coord(9,8)) ; 

	enemyMoveCount = 0 ;
}

SpaceInvaders::~SpaceInvaders(){}

void SpaceInvaders::runGame(){
	//setWindowSize(gridWidth, gridHeight);
	//GridGame::draw();

	change_horizontal_direction = FALSE ;
	leftAlert = FALSE ;
	rightAlert = FALSE ;

	while(true)
	{
		// use gamestates here
		Sleep(3000/TARGET_FPS);
		input.recieveinput();
		update();
		draw();
	}
}

void SpaceInvaders::update() // game logic
{
	gametime++;
	if(gametime>TARGET_FPS-1)
		gametime = 0;


	// check borders
	int leftCol = 0 ;
	int rightCol = gridWidth-1 ;
	int currentCol = leftCol ;
	leftAlert = FALSE ;
	rightAlert = FALSE ;

	for(int j = 0; j < gridHeight; ++j)
	{
		Entity* entity = world->getEntity(Coord(currentCol,j)) ;
		if(entity != nullptr && entity->getIdent() == "alien")
		{
				if(currentCol == leftCol) leftAlert = TRUE ;
				else if(currentCol == rightCol) rightAlert = TRUE ;
		}

		if(j == gridHeight-1 && currentCol == leftCol)
		{
			currentCol = rightCol ;
			j = 0 ;
		}
	}

	if(gametime%2==1)
	{
		if(leftAlert && rightAlert) setEnemiesDir(direction::none) ;
		else if(leftAlert || rightAlert)
		{
			if(change_horizontal_direction == FALSE)
			{
				setEnemiesDir(direction::down) ;
				change_horizontal_direction = TRUE ;
			}
			else if(leftAlert)
			{
				setEnemiesDir(direction::right) ;
				change_horizontal_direction = FALSE ;
			}
			else if(rightAlert)
			{
				setEnemiesDir(direction::left) ;
				change_horizontal_direction = FALSE ;
			}
		}
	}

	// cycle all entities in the world
	for(int i = 0; i < gridWidth; ++i)
	{
		for(int j = 0; j < gridHeight; ++j)
		{
			Entity* entity = world->getEntity(Coord(i,j)) ;
			if(entity != nullptr)
			{
				entity->cycle(*world, *settings, input, gametime) ;
			}
		}
	}

	// check for endgame
	for(int i = 0; i < gridWidth; ++i)
	{
		Entity* entity = world->getEntity(Coord(i,gridHeight-4)) ; // checking the row above barriers. if alien, kill game
		if(entity != nullptr && entity->getIdent() == "alien") exit(0) ;
	}
	

	/*
	if(gametime%2) enemyMoveCount++ ;

	// set alien's direction of motion
	// TODO: eventually dynamically align the enemy movement to the grid size. For now, assume default.
	if(enemyMoveCount == 6)
	{
		setEnemiesDir(down) ;
	}
	else if(enemyMoveCount == 7)
	{
		direction newDir = (lastDir == direction::left) ? direction::right : direction::left ;
		lastDir = newDir ;
		enemyMoveCount = 0 ;
		setEnemiesDir(newDir) ;
	}
	*/

}

void SpaceInvaders::draw() // TODO: revamp
{
	int margin = 2; // maybe unnecessary

	system("cls");
	cout << endl << endl; // leaves room for the HUD
	for(int i=0; i<gridHeight; ++i) {
		if(i==0 || i==gridHeight-1) {
			cout << endl << "|";
			for(int j=0; j<gridWidth+2; ++j)
				cout << "-";
			cout << "|";
		}
		else {
			cout << endl;
			cout << "|";
			for(int j=0; j<gridWidth+2; ++j)
				cout << " ";
			cout << "|";
		}
	}
	for(int i = 0; i < gridWidth; ++i) {
		for(int j = 0; j < gridHeight; ++j) {
			Entity* entity = world->getEntity(Coord(i,j)) ;
			if(entity != nullptr) {
				std::string ident = entity->getIdent();
				if(ident!= DEFAULT_GRID_IDENT && ident!="undefined"){
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					COORD pos;
					pos.X = i+margin; // maybe don't need margin when level editor is implemented
					pos.Y = j+margin;
					SetConsoleCursorPosition(hConsole, pos);
					cout<<graphics.at(ident);
				}
				// match ident to the graphics map and move the cursor to i,j and print that char
			}
		}
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(hConsole, pos);
	//can be placed at top or bottom
	//cout<<gametime;
	//cout << "Score: " << score ;
}

void SpaceInvaders::setEnemiesDir(direction m)
{
	for(int i = 0; i < gridWidth; ++i)
		for(int j = 0; j < gridHeight; ++j)
		{
			Entity* entity = world->getEntity(Coord(i,j)) ;
			if(entity != nullptr)
			{
				if(entity->getIdent() == "alien") entity->setDirection(m) ;
			}
		}
}
