#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "agent.h"
#include "state.h"
//this will hold our agent structs

//if agent interacts with 3 other infected agents- infected
//


bool contains(int arr[], int size, int value){

	for(int i=0; i<size; i++){

		if(arr[i] == value){
			return true;
		}

	}

	return false;

}

Agent* makeAgent(struct Graph* graph, int NAGENTS) {
	

	//memory for list of agents
	Agent* agents = malloc(NAGENTS * sizeof(Agent));
	float numInfected = NAGENTS*0.05;
	
	//counter to see how many have a disposition already
	int numAddict = 0;

	//10% of americans are addicted to drugs. 5% of ours will start addicted
	for(int i = 0; i<NAGENTS; i++){
		// initialize struct variables to 0 or false.
		agents[i].id = 0; 
		agents[i].homeNode = 0; 
		agents[i].currentNode = 0; 
		agents[i].isInfected = false; 
		agents[i].disposition = false; 
		agents[i].infectedEncounters = 0; 

		if(i< numInfected){
			agents[i].isInfected = true;
		}
		agents[i].id = i;
		//gotta make it deterministic??!!
		//also gotta make it random because 
		//agents[i].currentNode = ;
		
		

			
	}
	return agents;
}



int agentDisposition(struct Agent* agents, int NAGENTS){
	int twentyPercent = NAGENTS * 0.2;

                //printf("twentyPercent: %d\n", twentyPercent);
                //for size of 100, should have 20 with true disposition
                //next I want 20 random numbers between 0 and 99
                //make those 20 agents have a true disposition
                //

                //list to store agents who will have positive disposition
                
	
	int dispoAgents[twentyPercent];
	int countRepeats = 0;



	 for(int j= 0; j<twentyPercent; j++){
                        int whichAgent = rand() % NAGENTS;


                        //need ocntains function
			//
			//

		if (contains(dispoAgents, j, whichAgent) == false) {
                        dispoAgents[j] = whichAgent;
                        printf("randomNumber:: %d\n", whichAgent);
                }
                else {
                        countRepeats ++;
                }

                printf("j is: %d\n", j);
	}



                //but are there repeats?? need to acount for that
                //for 20 agents, try to get the agent at the i of dispoagent and make that agents disposition true
	for(int k = 0; k<twentyPercent; k++){
        	agents[dispoAgents[k]].disposition = true;
        }
	return(countRepeats);

}

void freeAgents(Agent* agents) {
    free(agents);
}
