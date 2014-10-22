/*

*/

#include "SpaceInvaders.h"

SpaceInvaders::SpaceInvaders(){
	
}

SpaceInvaders::~SpaceInvaders(){
	
}

void SpaceInvaders::runGame(){
	for(;;){
		input.recieveinput();
		update();
		draw();
	}
}

void SpaceInvaders::update()
{

}

void SpaceInvaders::draw()
{
	for(int i=0; i<DEFAULT_GRID_HEIGHT; i++) {
		for(int k=0; k<DEFAULT_GRID_WIDTH*4/1.3; k++) { cout << " "; if(k==DEFAULT_GRID_WIDTH*3) cout << endl; } // adds the spacing on top to place each entity in a 3x3 grid
		for(int j=0; j<DEFAULT_GRID_WIDTH; j++)
			//cout << "  " << convert[temp[i][j]] << " "; // runs through the display list to print the character to the screen	
			cout << " . " ;
	}
}
