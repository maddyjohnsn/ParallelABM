#include "state.h"
#include "agent.h"
#include "simulate.h"
#include <string.h>
#include <omp.h>

//will go through the Graph updating agent infection
void updateInfection(struct Graph* graph){
	// loop through each node
	#pragma omp parallel for
	for (int i = 0; i < graph->numNodes; i++) {
		// get node through there nodeID which should correspond to these indices
		
		struct Node* node = &graph->nodes[i];
		int infectedAtStartOfDay = node->numInfected;
		
		
		// in each node loop through agents in that node
		for (int j = 0; j < node->numAgents; j++) {
			if (node->agentsInNode[j]->isInfected == true) {
				continue;
			}
			// update encounters for each agent
			node->agentsInNode[j]->infectedEncounters += infectedAtStartOfDay;  ;
			// based on agents predisposition and number of encounters, update infection
			if (node->agentsInNode[j]->disposition == true && node->agentsInNode[j]->infectedEncounters >= 10) {
				node->agentsInNode[j]->isInfected = true;
				//data racing
				#pragma omp atomic
				node->numInfected++; 
			}
			if (node->agentsInNode[j]->disposition == false && node->agentsInNode[j]->infectedEncounters >= 15) {
				node->agentsInNode[j]->isInfected = true;
				
				//data racing
                                #pragma omp atomic
				node->numInfected++;
			}
		}

	}
}

void applyMoves(struct Agent* agents, PendingMove* moves, int numAgents, struct Graph* graph) {

	//need to reset nodes (but in parallel)
	//should make sure we're never data racing
	//rebuild from scratch every day
	#pragma omp parallel for
	for(int i = 0;i < graph->numNodes; i++){
		graph->nodes[i].numAgents = 0;
		graph->nodes[i].numInfected = 0;
		
	}

	//need to put agents in their destination node which we have stored in pending nodes
	//atoomic capture- 
	#pragma omp parallel for
	for(int i = 0;i <numAgents; i++){
		struct Agent* agent = &agents[moves[i].agentIndex];
		int dest = moves[i].destinationNode;
		struct Node* node = &graph->nodes[dest];
		//this all removes need for add and remove agent- maybe we can save more time with that later
		//every agent needs a unique spot to go into 
		int put;
		//let a node know it's numAgents again
		//updates memory location and captures its final value
		//might need a different compiler...
		#pragma omp atomic capture
		{
			put = node->numAgents;
			node->numAgents++;
		}

		node->agentsInNode[put] = agent;
		agent->currentNode = dest;

		if(agent->isInfected){
		
			#pragma omp atomic
			node->numInfected++;
		}
	}

	//need to specifically protect the count of agents in a node and the numInfected in a node

}

void moveAgent(struct Agent* agents, int numAgents, struct Graph* graph){
        int *directions = malloc(numAgents * sizeof(int));

        for (int i = 0; i < numAgents; i++) {
                directions[i] = rand() % 2;
        }

	//need to use our struct of PendingMove
	//

	PendingMove* moves = malloc(numAgents * sizeof(PendingMove));	

	#pragma omp parallel
	
		//still want random
		//replacement of random
//		unsigned int random = omp_get_thread_num() + time(NULL); 
	
		#pragma omp for
		for (int i = 0; i< numAgents; i++){

		//	struct Agent* agent = &agents[i];
			int current = agents[i].currentNode;
			int next;

			int flip = directions[i];
			//int flip = rand_r(&random) % 2;
			//check that movement will not push agent off graph- loop around
			if (flip == 0 ) { //moveBackwards
				next = current-1;
				if (next < 0){
					next = graph->numNodes - 1;
				}
			}else{
				next = current+1;
				if (next >= graph->numNodes){
					next = 0;

				}
			}


			//no more add and remove agent- do it in apply moves now
			//
			moves[i].agentIndex = i;
			moves[i].destinationNode = next;
			//don't forget to free moves
		}
	

	applyMoves(agents, moves, numAgents, graph);
	free(directions);
	free(moves);

}

void simulateDay(int days, struct Graph* graph,int numAgents, struct  Agent* agents, int* dailyInfectedCounts){

	//every day we want to move agents x2
	//maybe need to write data like below so we can run many simulations and not overwrite
	//fileName = multiDayOutput
	double moveAgentTotal = 0.0;
    	double updateInfectionTotal = 0.0;

	//create node locks for the whole simulation
	
	for(int i = 0; i<days; i++){
	
		moveAgent(agents, numAgents, graph);
		updateInfection(graph);

		//writeData(graph, "parallelOutput");

		//every day we need to increment a counter for num infected and save it
		//start by summing every infection across all nodes
		//
		int infectedCount = 0;
        	for (int j = 0; j < graph->numNodes; j++) {
            		infectedCount += graph->nodes[j].numInfected;
        	}
        	dailyInfectedCounts[i] = infectedCount;
		
	}

}
