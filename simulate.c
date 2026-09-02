#include "state.h"
#include "agent.h"
#include "simulate.h"

//will go through the Graph updating agent infection
void updateInfection(struct Graph* graph){
	// loop through each node
	for (int i = 0; i < graph->numNodes; i++) {
		// get node through there nodeID which should correspond to these indices
		struct Node* node = &graph->nodes[i];
		// in each node loop through agents in that node
		for (int j = 0; j < node->numAgents; j++) {
			if (node->agentsInNode[j]->isInfected == true) {
				continue;
			}
			// update encounters for each agent
			node->agentsInNode[j]->infectedEncounters += node->numInfected;  ;
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


