#include "GridGame.h"

GridGame::GridGame(){
	mysettings.open();//load the settings from the settings file
	//setup additional level stuff here

	setWindowSize(GRIDX*4/.95, GRIDY*3/1.3); // uses setWindowSize() to set the window, any numbers can be used
	temp.resize(GRIDY, vector<string>(GRIDX, " "));
	for(int i=0; i<GRIDY; i++)		// Use this loop to put the grid from world into the displayS vector
		for(int j=0; j<GRIDX; j++)
			temp[i][j]="Alien 1"; 
	temp[2][3]="Inactive";
	convert["Alien 1"] = "x";
	convert["Alien 2"] = "~";
	convert["Projectile"] = "*";
	convert["Player"] = "^";
	convert["Barrier full"] = "=";
	convert["Barrier half"] = "_";
	convert[DEFAULT_GRID_IDENT] = " ";
}

GridGame::~GridGame(){
	//setup settings here
	keyboardinput = keyboardinput(settings.getKeymap());//let keyinput know what keys to check for
}

void GridGame::rungame(){
	for(;;){
		keyboardinput.recieveinput();
		update();
		draw();
	}
}

void Game::setWindowSize(int x, int y) { // function to set the window size
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

void Game::draw() {
	for(int i=0; i<GRIDY; i++) {
		for(int k=0; k<GRIDX*4/1.3; k++) { cout << " "; if(k==GRIDX*3) cout << endl; } // adds the spacing on top to place each entity in a 3x3 grid
		for(int j=0; j<GRIDX; j++)
			cout << "  " << convert[temp[i][j]] << " "; // runs through the display list to print the character to the screen	
	}
	cout << endl;
	cout << endl;
	cout << endl;
}