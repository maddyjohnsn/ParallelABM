#include "state.h"
#include "agent.h"
#include "simulate.h"

//will go through the Graph updating agent infection
void updateInfection(struct Graph* graph){
	// loop through each node
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
			if (node->agentsInNode[j]->disposition == true && node->agentsInNode[j]->infectedEncounters >= 3) {
				node->agentsInNode[j]->isInfected = true;
				node->numInfected++; 
			}
			if (node->agentsInNode[j]->disposition == false && node->agentsInNode[j]->infectedEncounters >= 4) {
				node->agentsInNode[j]->isInfected = true;
				node->numInfected++;
			}
		}

	}
}

void moveAgent(struct Agent* agents, int numAgents, struct Graph* graph){
	for (int i = 0; i< numAgents; i++){

		struct Agent* agent = &agents[i];
		int current = agent->currentNode;
		int next;

		//randomly decide if agent is moving left or right
		int flip = rand() % 2;
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
		//remove agent from node
		removeAgentFromNode(graph, current, agent);
		//add agent to different node
		addAgentToNode(graph, next, agent);
			
	}

}

void simulateDay(int days, struct Graph* graph,int numAgents, struct  Agent* agents, int* dailyInfectedCounts){

	//every day we want to move agents x2
	//
	for(int i = 0; i<days; i++){
		moveAgent(agents, numAgents, graph);
		updateInfection(graph);

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
