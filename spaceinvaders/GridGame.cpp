#include "GridGame.h"

GridGame::GridGame(){
	mysettings.open();//load the settings from the settings file
	//setup additional level stuff here
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