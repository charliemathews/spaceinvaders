/*

*/

#include <Windows.h>
using namespace std ;

#include "KeyInput.h"

KeyInput::KeyInput(vector<char> keys){
	keybindings = keys;
}

KeyInput::~KeyInput(){}

void KeyInput::recieveinput(){
	for (int i = 0;i<keybindings.size();i++){
		char c = keybindings.at(i);
		keystate.at(keybindings.at(i)) = GetAsyncKeyState(c);
	}
}

bool KeyInput::isKeyDown(char k){
	return keystate.at(k);//returns the bool value of
}