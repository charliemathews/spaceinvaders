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


	// LOAD SETTINGS FROM FILE
	vector<vector<string>> world_input = GridGame::data->linesMatching("world") ;
	for(auto &p : world_input)
	{
		// LOAD ENTITIES
		if(p.size() == 3 && p[1] == "entity")
		{
			stringstream ss ;
			ss << p[2] ;

			string segment;
			vector<string> seglist;

			while(getline(ss, segment, ' '))
			{
			   seglist.push_back(segment);
			}

			if(seglist.size() == 3)
			{
				Entity* newEnt = nullptr ;
				string ident = seglist[0] ;
				
				// DEFINE LOADABLE ENTITIES
				if(ident == "barrier") newEnt = new Barrier() ;
				if(ident == "alien") newEnt = new Alien() ;
	
				int x, y;
				ss.clear() ;
				ss << seglist[1] ;
				ss >> x ;
				ss.clear() ;
				ss << seglist[2] ;
				ss >> y ;

				if(newEnt != nullptr) world->add(newEnt,Coord(x,y)) ;
			}
		}
	}

	enemyMoveCount = 0 ;
	gamestate = MENU ;
	isAdd=false;
	isDelete=false;
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
		// use gamestates to decide action
		if(gamestate == PLAY)
		{
			Sleep(3000/TARGET_FPS);
			input.recieveinput();
			update();
			draw();
		}
		else if(gamestate == MENU)
		{
			system("cls") ;
			cout << "MAIN MENU" << endl << endl ;
			cout << "(1) Play Game" << endl ;
			cout << "(2) Edit Level" << endl ;
			cout << "(3) Highscores" << endl ;
			cout << "(4) Quit" << endl << endl ;

			cout << "Choose an option:" ;
			int option ;
			cin >> option ;

			if(option == 1) gamestate = PLAY ;
			else if(option == 2) gamestate = mode::EDIT ;
			else if(option == 3) gamestate = mode::HIGHSCORES ;
			else if(option == 4) gamestate = mode::QUIT ;
			else gamestate = mode::MENU ;
		} 

		else if(gamestate == EDIT)
		{
			editorReadFile();
			gamestate=mode::MENU;
			// level editor call here!
		}
		else if(gamestate == HIGHSCORES)
		{
			//output highscores, future todo
			gamestate = mode::MENU ;
		}
		else if(gamestate == QUIT)
		{
			exit(0) ;
		}
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
		if(entity != nullptr && entity->getIdent() == "alien") gamestate = MENU ; //exit(0) ;
	}

}

void SpaceInvaders::draw()
{
	int margin = 2;

	system("cls");
	/*
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
	*/
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

void SpaceInvaders::editorReadFile() {
	system("cls");
	cout << "LEVEL EDITOR" << endl;
	Parser onPar = Parser("spaceinvaders.dat",'.', '=');
	settingsEditor = onPar.linesMatching("setting");
	barrierEditor = onPar.linesContaining("barrier",2);
	alienEditor = onPar.linesContaining("alien", 2);
	int selection=0;
	cout << endl <<"0. Escape"<<endl << "1. Edit grid" << endl << "2. Edit settings" << endl << endl << "Selection: ";
	cin >> selection;
	do {
		if (selection==0) gamestate = MENU;
		else if(selection==1) editorDrawGrid();
		else if(selection==2) editorDrawSettings();
		else {
			cout << "Make a valid selection (1/2): ";
			cin >> selection;
		}
	}while(selection<0 || selection>2);
}

void SpaceInvaders::editorDrawGrid() {
	system("cls");
	int gameWidth = 0, gameHeight = 0;
	string heightPref="gridheight ";
	string widthPref="gridwidth ";
	for(vector<vector<string>>::iterator it1 = settingsEditor.begin(); it1 != settingsEditor.end(); ++it1) {
		string argument=(*it1).at(2);
		if(argument.substr(0, heightPref.size()) == heightPref) {
			string heightValue = argument.substr(heightPref.size());
			gameHeight = atoi(heightValue.c_str());
		}
		if(argument.substr(0, widthPref.size()) == widthPref) {
			string widthValue = argument.substr(widthPref.size());
			gameWidth = atoi(widthValue.c_str());
		}
	}
	setWindowSize(2*(gameWidth)+15, gameHeight+7);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=2;
	pos.Y=0;
	SetConsoleCursorPosition(hConsole, pos);
	for(int i=0; i<gameWidth/10; ++i) {
		pos.X+=20;
		SetConsoleCursorPosition(hConsole, pos);
		cout << i+1;
	}
	pos.X=0;
	pos.Y=2;
	SetConsoleCursorPosition(hConsole, pos);
	for(int i=0; i<gameHeight/10; ++i) {
		pos.Y+=10;
		SetConsoleCursorPosition(hConsole, pos);
		cout << i+1;
	}
	pos.X=0;
	pos.Y=1;
	SetConsoleCursorPosition(hConsole, pos);
	for(int i=0; i<gameWidth; ++i) {
		pos.X+=2;
		SetConsoleCursorPosition(hConsole, pos);
		cout << i%10;
	}
	pos.X=1;
	pos.Y=1;
	SetConsoleCursorPosition(hConsole, pos);
	for(int i=0; i<gameHeight; ++i) {
		pos.Y+=1;
		SetConsoleCursorPosition(hConsole, pos);
		cout << i%10;
	}
	pos.X=0;
	pos.Y+=2;
	SetConsoleCursorPosition(hConsole, pos);
	vector<int> barrierX;
	vector<int> barrierY;
	for(int i=0; i<barrierEditor.size(); i++) {
		vector<string> temp;
		char str[500];
		strcpy(str, barrierEditor.at(i).at(2).c_str());
		char * ptr = strtok(str, " ");
		while(ptr !=nullptr){
			temp.push_back(std::string(ptr));
			ptr = strtok(NULL, " ");
		}
		barrierX.push_back(stoi(temp.at(1)));
		barrierY.push_back(stoi(temp.at(2)));
	}
	for(int i=0; i<barrierX.size(); i++) {
		pos.X=2*(barrierX.at(i))+2;
		pos.Y=(barrierY.at(i))+2;
		SetConsoleCursorPosition(hConsole, pos);
		cout << "=";
	}
	vector<int> alienX;
	vector<int> alienY;
	for(int i=0; i<alienEditor.size(); i++) {
		vector<string> temp;
		char str[500];
		strcpy(str, alienEditor.at(i).at(2).c_str());
		char * ptr = strtok(str, " ");
		while(ptr !=nullptr){
			temp.push_back(std::string(ptr));
			ptr = strtok(NULL, " ");
		}
		alienX.push_back(stoi(temp.at(1)));
		alienY.push_back(stoi(temp.at(2)));
	}
	for(int i=0; i<alienX.size(); i++) {
		pos.X=2*(alienX.at(i))+2;
		pos.Y=(alienY.at(i))+2;
		SetConsoleCursorPosition(hConsole, pos);
		cout << "V";
	}
	pos.X=0;
	pos.Y=gameHeight+2;
	SetConsoleCursorPosition(hConsole, pos);
	if(isAdd) editorAdd();
	else if(isDelete) editorDelete();
	else editorGridMenu();
	//system("Pause");
}

void SpaceInvaders::editorGridMenu() {
	isAdd=false;
	isDelete=false;
	int selection=0;
	cout << "Grid editor:" << endl << "0. Escape" << endl << "1. Add" << endl << "2. Delete" << endl;
	cout << endl << "Selection: ";
	cin >> selection;
	do {
		if(selection==0) {
			isAdd=false;
			isDelete=false;
			editorReadFile();
		}
		else if(selection==1) {
			isAdd=true;
			isDelete=false;
			editorDrawGrid();
		}
		else if(selection==2) {
			isAdd=false;
			isDelete=true;
			editorDrawGrid();
		}
		else {
			cout << "Please enter valid selection (0/1/2): ";
			cin >> selection;
		}
	}while(selection<0||selection>2);
}

void SpaceInvaders::editorAdd() {
	isAdd=false;
	isDelete=false;
	Parser onPar = Parser("spaceinvaders.dat",'.', '=');
	cout << "V = alien, = = barrier";
	string addEntity;
	cout << endl << "Add (type x y): ";
	std::getline(cin, addEntity);
	std::getline(cin, addEntity);
	vector<string> temp;
	char str[500];
	strcpy(str, addEntity.c_str());
	char * ptr = strtok(str, " ");
	while(ptr !=nullptr){
		temp.push_back(std::string(ptr));
		ptr = strtok(NULL, " ");
	}
	string temp2=temp.at(0)+" "+temp.at(1)+" "+temp.at(2);
	onPar.deleteMatching(temp2, 2);
	addEntity="world.entity="+temp2;
	onPar.add(addEntity);
	onPar.saveToFile();
	editorReadFile();
}

void SpaceInvaders::editorDelete() {
	isAdd=false;
	isDelete=false;
	Parser onPar = Parser("spaceinvaders.dat",'.', '=');
	cout << "V = alien, = = barrier";
	string deleteEntity;
	cout << endl << "Delete (type x y): ";
	std::getline(cin, deleteEntity);
	std::getline(cin, deleteEntity);
	vector<string> temp;
	char str[500];
	strcpy(str, deleteEntity.c_str());
	char * ptr = strtok(str, " ");
	while(ptr !=nullptr){
		temp.push_back(std::string(ptr));
		ptr = strtok(NULL, " ");
	}
	string temp2=temp.at(0)+" "+temp.at(1)+" "+temp.at(2);
	onPar.deleteMatching(temp2, 2);
	deleteEntity="world.entity="+temp2;
	onPar.saveToFile();
	editorReadFile();
}

void SpaceInvaders::editorDrawSettings() {
	Parser onPar = Parser("spaceinvaders.dat",'.', '=');
	cout << endl << "Settings:" << endl;
	for(vector<vector<string>>::iterator it1 = settingsEditor.begin(); it1 != settingsEditor.end(); ++it1)
		cout << (*it1).at(1) << " " << (*it1).at(2) << endl;
	string newSetting;
	cout << endl << "Enter new setting: ";
	std::getline(cin, newSetting);
	std::getline(cin, newSetting);
	vector<string> temp;
	char str[500];
	strcpy(str, newSetting.c_str());
	char * ptr = strtok(str, " ");
	while(ptr !=nullptr){
		temp.push_back(std::string(ptr));
		ptr = strtok(NULL, " ");
	}
	onPar.deleteContaining(temp.at(1), 2);
	newSetting="setting."+temp.at(0)+"="+temp.at(1)+" "+temp.at(2);
	onPar.add(newSetting);
	onPar.saveToFile();
	editorReadFile();
}