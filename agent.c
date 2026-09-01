#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//this will hold our agent structs
//

#define NAGENTS 20

typedef struct {
	int id;
	int homeNode;
	int currentNode;
	bool isInfected;
	bool disposition;
	//using a fixed size array for this next one because we know it's max... would changing the memory later on be faster?
	int encounters[NAGENTS];

}Agent;

//if agent interacts with 3 other infected agents- infected
//

void wakeAgent(){

	for (int i = 0){
	
		agents[i].homeNode = rand() % graph->numNodes;
    		agents[i].currentNode = -1; // not placed yet
    		for (int j = 0; j < NAGENTS; j++){
			agents[i].encounters[j] = 0;
		}

	}

}

Agent*  makeAgent(int NAGENTS, struct Graph* graph) {
	

	//memory for list of agents
	Agent* agents = malloc(NAGENTS * sizeof(Agent));
	float numInfected = NAGENTS*0.05;
	
	//counter to see how many have a disposition already
	int numAddict = 0;

	//10% of americans are addicted to drugs. 5% of ours will start addicted
	for(int i = 0; i<NAGENTS; i++){
		if(i< numInfected){
			agents[i].isInfected = true;
		}
		agents[i].id = i;
		//gotta make it deterministic??!!
		//also gotta make it random because 
		//agents[i].currentNode = ;
		
		//maybe like 20% are moderately prone to addiction. 20 are heavily prone and 60 are just average
		int randomInfect = rand() % 21;
		if(randomInfect > 16 && numAddict < NAGENTS/5){
			numAddict ++;
			agents[i].disposition = true;
			
		}
		else{
			agents[i].disposition = false;
		}
		
	}
		

	return agents;
}
