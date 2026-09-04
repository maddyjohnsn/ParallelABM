#include "state.h"
#include "agent.h"
#include "simulate.h"

int main(int argc, char *argv[]){

	int err;
    	if(argc!=3 ) {
        	printf("Missing the first argument:  number of agents to create\n");
        	printf("Missing the second argument:  number of nodes to create\n");
		return 1;
    	}

	int NAGENTS = atoi(argv[1]);
	int NNODES = atoi(argv[2]);

        struct Graph* undirectedGraph = createGraph(NNODES);

        addRingEdges(undirectedGraph, 3);

        Agent* agentsList = makeAgent(undirectedGraph, NAGENTS);
	for (int i = 0; i< NAGENTS; i++) {
		addAgentToNode(undirectedGraph, i%NNODES, &agentsList[i]);
	}
	int numAgents = NAGENTS; 

	agentDisposition(agentsList, NAGENTS);

        showGraph(undirectedGraph);
        for (int i = 0; i < NAGENTS; i++) {
                printf("isInfected: %d  currentNode: %d\n", agentsList[i].isInfected, agentsList[i].currentNode);
                printf("isInfected: %d  currentNode: %d    disposition: %d\n", agentsList[i].isInfected, agentsList[i].currentNode, agentsList[i].disposition);
	}
	writeData(undirectedGraph, "testOutput.csv");	
	moveAgent(agentsList, numAgents, undirectedGraph);
	updateInfection(undirectedGraph);
	writeData(undirectedGraph, "testOutput1step.csv"); 
       	showGraph(undirectedGraph); 
        for (int i = 0; i < NAGENTS; i++) {
                printf("isInfected: %d  currentNode: %d\n", agentsList[i].isInfected, agentsList[i].currentNode);
        }   
	moveAgent(agentsList, numAgents, undirectedGraph);
	updateInfection(undirectedGraph); 
	freeAgents(agentsList);
	freeGraph(undirectedGraph);
	return 0;


}
