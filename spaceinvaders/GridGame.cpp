#include "GridGame.h"
#include "Settings.h"
#include "KeyInput.h"

GridGame::GridGame(string config, int w, int h) : gridWidth(w), gridHeight(h)
{
	settings = new Settings() ; //"settings.config"
	input = KeyInput(settings->getKeyBindings()) ;
	setWindowSize(w*4/.95, h*3/1.3) ;
	gametime = 0;
}

GridGame::~GridGame(){}

void GridGame::updateScore(int s) { }//score += s ; }

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
