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

void moveAgent(struct Agent* agents, int numAgents, struct Graph* graph){

	#pragma omp parallel
	{
		//replacement of random
		unsigned int random = omp_get_thread_num() + time(NULL); 
	
		#pragma omp for
		for (int i = 0; i< numAgents; i++){

			struct Agent* agent = &agents[i];
			int current = agent->currentNode;
			int next;

			int flip = rand_r(&random) % 2;
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
			// need to protect these because they work on shared node data- probably need to be in the same lock- might not do much
			#pragma omp critical
			{
			//remove agent from node
			removeAgentFromNode(graph, current, agent);
			//add agent to different node
			addAgentToNode(graph, next, agent);
			}
		}
	}

}

void simulateDay(int days, struct Graph* graph,int numAgents, struct  Agent* agents, int* dailyInfectedCounts){

	//time it
	//
	double moveAgentTotal = 0.0;
    	double updateInfectionTotal = 0.0;

	//every day we want to move agents x2
	//maybe need to write data like below so we can run many simulations and not overwrite
	//fileName = multiDayOutput
	
	
	for(int i = 0; i<days; i++){
	
		double t0 = omp_get_wtime();
		moveAgent(agents, numAgents, graph);
		double t1 = omp_get_wtime();
		updateInfection(graph);
		double t2 = omp_get_wtime();

		moveAgentTotal += (t1 - t0);
        	updateInfectionTotal += (t2 - t1);

		writeData(graph, "multiDayOutput");

		//every day we need to increment a counter for num infected and save it
		//start by summing every infection across all nodes
		//
		int infectedCount = 0;
        	for (int j = 0; j < graph->numNodes; j++) {
            		infectedCount += graph->nodes[j].numInfected;
        	}
        	dailyInfectedCounts[i] = infectedCount;
		
	}

	printf("Total time in moveAgent:       %f seconds\n", moveAgentTotal);
	printf("Total time in updateInfection: %f seconds\n", updateInfectionTotal);
	printf("moveAgent fraction of total:    %.1f%%\n",100.0 * moveAgentTotal / (moveAgentTotal + updateInfectionTotal));

}
