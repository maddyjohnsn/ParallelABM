#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "state.h"

//this will hold our agent structs
//


typedef struct Agent {
	int id;
	int homeNode;
	int currentNode;
	bool isInfected;
	bool disposition;

	//using a fixed size array for this next one because we know it's max... would changing the memory later on be faster?
	int infectedEncounters;
}Agent;

//if agent interacts with 3 other infected agents- infected
//

//void wakeAgent();

Agent*  makeAgent(struct Graph* graph, int NAGENTS) ;

int agentDisposition(struct Agent* agents, int NAGENTS);

void freeAgents(Agent* agents);
