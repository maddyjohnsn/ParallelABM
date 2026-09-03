#include "state.h"
#include "agent.h"
#include "simulate.h"

int main(){


        struct Graph* undirectedGraph = createGraph(8);

        addRingEdges(undirectedGraph, 3);

        Agent* agentsList = makeAgent(undirectedGraph);
	for (int i = 0; i< NAGENTS; i++) {
		addAgentToNode(undirectedGraph, i%8, &agentsList[i]);
	}
	int numAgents = NAGENTS; 

        showGraph(undirectedGraph);
        for (int i = 0; i < NAGENTS; i++) {
                printf("isInfected: %d  currentNode: %d\n", agentsList[i].isInfected, agentsList[i].currentNode);
	}
	writeData(undirectedGraph, "testOutput.csv");	
	moveAgent(agentsList, numAgents, undirectedGraph);
	updateInfection(undirectedGraph);
	writeData(undirectedGraph, "testOutput1step.csv"); 
       	showGraph(undirectedGraph); 
        for (int i = 0; i < NAGENTS; i++) {
                printf("isInfected: %d  currentNode: %d\n", agentsList[i].isInfected, agentsList[i].currentNode);
        }   
	freeAgents(agentsList);
	freeGraph(undirectedGraph);
	return 0;


}
