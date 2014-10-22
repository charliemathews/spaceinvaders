#include "GridGame.h"
#include "Settings.h"
#include "KeyInput.h"

GridGame::GridGame(){
	settings = Settings("settings.config"); //load the settings from the settings file
	input = KeyInput(settings.getKeyBindings());
	//setup additional level stuff here

	setWindowSize(DEFAULT_GRID_WIDTH*4/.95, DEFAULT_GRID_HEIGHT*3/1.3); // uses setWindowSize() to set the window, any numbers can be used
	
	//temp.resize(DEFAULT_GRID_HEIGHT, vector<string>(DEFAULT_GRID_WIDTH, " "));
	//for(int i=0; i<DEFAULT_GRID_HEIGHT; i++)		// Use this loop to put the grid from world into the displayS vector
	//	for(int j=0; j<DEFAULT_GRID_WIDTH; j++)
	//		temp[i][j]="Alien 1"; 
	//temp[2][3]="Inactive";

	graphics["Alien 1"] = "x";
	graphics["Alien 2"] = "~";
	graphics["Projectile"] = "*";
	graphics["Player"] = "^";
	graphics["Barrier full"] = "=";
	graphics["Barrier half"] = "_";
	graphics[DEFAULT_GRID_IDENT] = " ";
}

GridGame::~GridGame(){
	//setup settings here
	//input = input(settings.getKeymap());//let keyinput know what keys to check for
}

void GridGame::setWindowSize(int x, int y) { // function to set the window size
	if(x>240) x=240; // prevents crashing if window size is too large
	if(y>84) y=84;
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    if (h==INVALID_HANDLE_VALUE)
        throw std::runtime_error("Unable to get stdout handle.");

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
        throw std::runtime_error("Unable to retrieve screen buffer info.");

    SMALL_RECT& winInfo=bufferInfo.srWindow;
    COORD windowSize;
	windowSize.X=winInfo.Right-winInfo.Left+1;
	windowSize.Y=winInfo.Bottom-winInfo.Top+1;


    if (windowSize.X>x || windowSize.Y>y) {
        SMALL_RECT info;
		info.Left=0;
		info.Right=x<windowSize.X ? x-1 : windowSize.X-1;
		info.Top=0;
		info.Bottom=y<windowSize.Y ? y-1 : windowSize.Y-1;

        if (!SetConsoleWindowInfo(h, TRUE, &info))
            throw std::runtime_error("Unable to resize window before resizing buffer.");
    }

    COORD size;
	size.X=x;
	size.Y=y;
    if (!SetConsoleScreenBufferSize(h, size))
        throw std::runtime_error("Unable to resize screen buffer.");

    SMALL_RECT info;
	info.Left=0;
	info.Right=x-1;
	info.Top=0;
	info.Bottom=y-1;

    if (!SetConsoleWindowInfo(h, TRUE, &info))
        throw std::runtime_error("Unable to resize window after resizing buffer.");
}
