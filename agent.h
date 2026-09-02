#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "state.h"

//this will hold our agent structs
//

#define NAGENTS 20

typedef struct Agent {
	int id;
	int homeNode;
	int currentNode;
	bool isInfected;
	bool disposition;
	//encounters could be bigger than the number of agents...
	int* encounters;

}Agent;

//if agent interacts with 3 other infected agents- infected
//

//void wakeAgent();

Agent*  makeAgent(int numAgents, struct Graph* graph) ;
