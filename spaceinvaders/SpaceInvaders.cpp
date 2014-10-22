/*

*/

#include "SpaceInvaders.h"
#include "Player.h"
#include "Barrier.h"
#include "Projectile.h"
#include "Alien.h"

SpaceInvaders::SpaceInvaders(string config, int w, int h) : GridGame(config,w,h)
{
	graphics["player"] = "^";
	graphics["alien"] = "V";
	graphics["projectile"] = "*";
	graphics["barrier"] = "=";
	graphics[DEFAULT_GRID_IDENT]	= " ";

	Player* thePlayer = new Player() ;

	world.add(thePlayer, Coord(0,world.size('y')-1)) ; // player always spawns in bottom left
	
	world.add(new Barrier(), Coord(1,17)) ;
	world.add(new Barrier(), Coord(4,17)) ;
	world.add(new Barrier(), Coord(7,17)) ;
	world.add(new Barrier(), Coord(10,17)) ;
	world.add(new Barrier(), Coord(13,17)) ;

	world.add(new Alien(), Coord(1,2)) ;
	world.add(new Alien(), Coord(3,2)) ;
	world.add(new Alien(), Coord(5,2)) ;
	world.add(new Alien(), Coord(7,2)) ;
	world.add(new Alien(), Coord(9,2)) ;

	world.add(new Alien(), Coord(1,4)) ;
	world.add(new Alien(), Coord(3,4)) ;
	world.add(new Alien(), Coord(5,4)) ;
	world.add(new Alien(), Coord(7,4)) ;
	world.add(new Alien(), Coord(9,4)) ; 

	world.add(new Alien(), Coord(1,6)) ;
	world.add(new Alien(), Coord(3,6)) ;
	world.add(new Alien(), Coord(5,6)) ;
	world.add(new Alien(), Coord(7,6)) ;
	world.add(new Alien(), Coord(9,6)) ; 

	world.add(new Alien(), Coord(1,8)) ;
	world.add(new Alien(), Coord(3,8)) ;
	world.add(new Alien(), Coord(5,8)) ;
	world.add(new Alien(), Coord(7,8)) ;
	world.add(new Alien(), Coord(9,8)) ; 

}

SpaceInvaders::~SpaceInvaders(){}

void SpaceInvaders::runGame(){
	for(;;){
		Sleep(1000/TARGET_FPS);
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
	// Cycle all entities in the world.
	int sizex = world.size('x') ;
	int sizey = world.size('y') ;

	for(int i = 0; i < sizex; ++i)
	{
		for(int j = 0; j < sizey; ++j)
		{
			Entity* entity = world.getEntity(Coord(i,j)) ;
			if(entity != nullptr) entity->cycle(world, *settings, input, 0) ;
		}
	}
}

void SpaceInvaders::draw() // TODO: revamp
{
	//for(int i=0; i<gridHeight; i++) {
	//	for(int k=0; k<gridWidth*4/1.3; k++) { cout << " "; if(k==gridWidth*3) cout << endl; } // adds the spacing on top to place each entity in a 3x3 grid
	//	for(int j=0; j<gridWidth; j++)
	//		//cout << "  " << convert[temp[i][j]] << " "; // runs through the display list to print the character to the screen	
	//		cout << " . " ;
	//}
	system("cls");
	for(int i = 0; i < gridWidth; ++i)
	{
		for(int j = 0; j < gridHeight; ++j)
		{
			Entity* entity = world.getEntity(Coord(i,j)) ;
			if(entity != nullptr)
			{
				std::string ident = entity->getIdent();
				if (ident!= DEFAULT_GRID_IDENT && ident!="undefined"){
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					COORD pos;
					pos.X = i;
					pos.Y = j;
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
	cout<<gametime;

}
