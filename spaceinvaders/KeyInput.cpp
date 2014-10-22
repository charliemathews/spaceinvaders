#include "KeyInput.h"

KeyInput::KeyInput(vector<char> keys){
	keybindings = k;
}

KeyInput::~KeyInput(){}

KeyInput::recieveinput(){
	for (int i = 0;i<keybindings.size();i++){
		char c = keybindings.at(i);
		keystate.at(keybindings.at(i)) = GetAsyncKeyState();
	}
}

KeyInput::isKeyDown(char k){
	return keystate.at(k);//returns the bool value of}