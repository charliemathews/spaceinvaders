#include "GridGame.h"
#include "Settings.h"
#include "KeyInput.h"
#include "Parser.h"

#include <Windows.h>
using namespace std ;

GridGame::GridGame(string config)
{
	//create parser as protected so derrived game, spaceinvaders, can use it too
	Parser onPar = Parser("spaceinvaders.dat",'.','=');

	//LOAD CONFIG DATA -=-=-=-=-=-=-=-=-=-=-

		// -> settings 
		settings = new Settings(onPar.linesMatching("setting")); 

		// -> input
		input = KeyInput(settings->getKeyBindings()) ;

		// -> graphics

		// -> world
		gridWidth = DEFAULT_GRID_WIDTH ; // get these from the parser
		gridHeight = DEFAULT_GRID_HEIGHT ;
		world = new World(gridWidth,gridHeight) ;
			// insert entities into world in space invaders


	//INITIAL SETUP
	setWindowSize(gridWidth,gridHeight);
	gametime = 0;
}

GridGame::~GridGame(){}

void GridGame::setWindowSize(int x, int y) { // function to set the window size
	x+=5;
	y+=5;
	if(x>240) x=240; // prevents crashing if window size is too large
	if(y>84) y=84;
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    if(h==INVALID_HANDLE_VALUE)
        throw std::runtime_error("Unable to get stdout handle.");

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    if(!GetConsoleScreenBufferInfo(h, &bufferInfo))
        throw std::runtime_error("Unable to retrieve screen buffer info.");

    SMALL_RECT& winInfo=bufferInfo.srWindow;
    COORD windowSize;
	windowSize.X=winInfo.Right-winInfo.Left+1;
	windowSize.Y=winInfo.Bottom-winInfo.Top+1;


    if(windowSize.X>x || windowSize.Y>y) {
        SMALL_RECT info;
		info.Left=0;
		info.Right=x<windowSize.X ? x-1 : windowSize.X-1;
		info.Top=0;
		info.Bottom=y<windowSize.Y ? y-1 : windowSize.Y-1;

        if (!SetConsoleWindowInfo(h, TRUE, &info))
            throw std::runtime_error("Unable to resize window before resizing buffer.");
	}
}
