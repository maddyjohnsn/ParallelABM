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

omp_lock_t* createNodeLocks(int numNodes) {
	//need to create array of locks I think
	//get lock objects that goes with a node
	//next can give us that index?
	//number tell us which lock to lock in the array
	// https://stackoverflow.com/questions/40770263/omp-init-lockomp-lock-t-what-does-this-function-do-exactly stack overflow help
	
	omp_lock_t* locks = malloc(numNodes * sizeof(omp_lock_t));
	for (int i = 0; i < numNodes; i++){
		omp_init_lock(&locks[i]);
	}
	return locks;
}

void destroyNodeLocks(omp_lock_t* locks, int numNodes) {
	//exact reverse but to free
	for (int i = 0; i < numNodes; i++){
                omp_destroy_lock(&locks[i]);
        }       
	free(locks);
}

void moveAgent(struct Agent* agents, int numAgents, struct Graph* graph, omp_lock_t* nodeLocks){

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

			// lock the lower-numbered node first
			// makes sure that two nodes can't both be locked and prevent the agent from moving forever
            		int lockFirst = (current < next) ? current : next;
            		int lockSecond = (current < next) ? next : current;

			omp_set_lock(&nodeLocks[lockFirst]);
            		omp_set_lock(&nodeLocks[lockSecond]);

			// need to protect these because they work on shared node data- probably need to be in the same lock- might not do much
			#pragma omp critical
			{
			//remove agent from node
			removeAgentFromNode(graph, current, agent);
			//add agent to different node
			addAgentToNode(graph, next, agent);
			
			omp_unset_lock(&nodeLocks[lockFirst]);
            		omp_unset_lock(&nodeLocks[lockSecond]);
			}
		}
	}

}

void simulateDay(int days, struct Graph* graph,int numAgents, struct  Agent* agents, int* dailyInfectedCounts){

	//every day we want to move agents x2
	//maybe need to write data like below so we can run many simulations and not overwrite
	//fileName = multiDayOutput
	

	//create node locks for the whole simulation
	omp_lock_t* nodeLocks = createNodeLocks(graph->numNodes);
	
	for(int i = 0; i<days; i++){
	
		moveAgent(agents, numAgents, graph, nodeLocks);
		updateInfection(graph);

	//	writeData(graph, "parallelOutput");

		//every day we need to increment a counter for num infected and save it
		//start by summing every infection across all nodes
		//
		int infectedCount = 0;
        	for (int j = 0; j < graph->numNodes; j++) {
            		infectedCount += graph->nodes[j].numInfected;
        	}
        	dailyInfectedCounts[i] = infectedCount;
		
	}
	destroyNodeLocks(nodeLocks, graph->numNodes);

}
