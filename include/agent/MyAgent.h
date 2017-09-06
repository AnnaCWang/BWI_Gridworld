#ifndef MyAgent_h__guard
#define MyAgent_h__guard


#include <grid/Agent.h>

struct MyAgent : public bwi_gridworld::Agent {
	MyAgent(int id);
    char nextAction(const bwi_gridworld::Pos &currentPos);
    void eventFound(const bwi_gridworld::Pos &currentPos);
    bwi_gridworld::Agent *clone(int id);
	char moveAgent01 (int xPos, int yPos, int interval);
	char moveAgent23 (int xPos, int yPos, int interval);

    int agent;

};


#endif
