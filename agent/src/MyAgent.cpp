#include <agent/MyAgent.h>
#include <iostream>
#include <cstdlib>
#include "grid/grid.h"//check position of robot just in case it would run into the wall
using namespace std;


MyAgent::MyAgent(int id) {
	agent = id;
}

bwi_gridworld::Agent* MyAgent::clone(int id) {
	
    return new MyAgent(id); 
} 

// moving agent 0 or 1 in a path
char MyAgent::moveAgent01 (int posX, int posY, int interval) {
	if (posX == 0 + interval && (posY == 0 || posY == 1 || posY == 2 || posY == 3 || posY == 4) )
		return 'n';
	if ((posX == 0 + interval || posX == 1 + interval || posX == 2 + interval || posX == 3 + interval)  && posY == 5)
		return 'e';
	if (posX == 4 + interval && (posY == 5 || posY == 3 || posY == 1))
		return 's';
	if ((posX == 4 + interval || posX == 3 + interval || posX == 2 + interval) && posY == 4)
		return 'w';
	if (posX == 1 + interval && (posY == 4 || posY ==2))
		return 's';
	if ((posX == 1 + interval || posX == 2 + interval || posX == 3 + interval) && posY == 3)
		return 'e';
	if ((posX == 4 + interval || posX == 3 + interval || posX == 2 + interval) && posY == 2)
		return 'w';
	if ((posX == 1 + interval || posX == 2 + interval || posX == 3 + interval) && posY == 1)
		return 'e';
	if ((posX == 4 + interval || posX == 3 + interval || posX == 2 + interval || posX == 1 + interval) && posY == 0)
		return 'w';
}

// moving agent 2 or 3 in a path
char MyAgent::moveAgent23 (int posX, int posY, int interval) {
	if (posX == 0 + interval && (posY == 6 || posY == 7 || posY == 8)) 
		return 'n';
	if ((posX == 0 + interval || posX == 1 + interval || posX == 2 + interval || posX == 3 + interval) && posY == 9) 
		return 'e';
	if (posX == 4 + interval && (posY == 9 || posY == 7)) 
		return 's';
	if ((posX == 4 + interval || posX == 3 + interval || posX == 2 + interval) && posY == 8)
		return 'w';
	if (posX == 1 + interval && posY == 8) 
		return 's';
	if ((posX == 1 + interval || posX == 2 + interval || posX == 3 + interval) && posY == 7)
		return 'e';
	if ((posX == 4 + interval || posX == 3 + interval || posX == 2 + interval || posX == 1 + interval) && posY == 6)
		return 'w';
}

// returns the next direction to go to
char MyAgent::nextAction(const bwi_gridworld::Pos& currentPos) {
	
	bwi_gridworld::Pos posGo (currentPos.x, currentPos.y, 0); //make object for current position
	int posX = posGo.x;
	int posY = posGo.y;
	if (agent == 0)
		return moveAgent01(posX, posY, 0);
	if (agent == 1) 
		return moveAgent01(posX, posY, 5);
	if (agent == 2) 
		return moveAgent23(posX, posY, 5);
	if (agent == 3) {
		return moveAgent23(posX, posY, 0);
	}
    return 'n';
}


// called if event is found (does nothing)
void MyAgent::eventFound(const bwi_gridworld::Pos &currentPos) {		
	   //cout << "-----found event!------ ( " << posGo.x << ", " << posGo.y << ") ------------" << endl;
	}
	

