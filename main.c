#include "state.h"
#include "agent.h"
#include "simulate.h"

int main(int argc, char *argv[]){

	//use the right arguments
	int err;
    	if(argc!=4 ) {
        	printf("Missing the first argument:  number of agents to create\n");
        	printf("Missing the second argument:  number of nodes to create\n");
		printf("Missing the third argument:  number of days to create\n");

		return 1;
    	}



	int NAGENTS = atoi(argv[1]);
	int NNODES = atoi(argv[2]);
	int DAYS = atoi(argv[3]);

	//make graph and agents
        struct Graph* undirectedGraph = createGraph(NNODES);
        addRingEdges(undirectedGraph, 3);
        Agent* agentsList = makeAgent(undirectedGraph, NAGENTS);
	
	//add agents to nodes
	for (int i = 0; i< NAGENTS; i++) {
		addAgentToNode(undirectedGraph, i%NNODES, &agentsList[i]);
	}
	int numAgents = NAGENTS; 
	
	//add agent dispositions
	agentDisposition(agentsList, NAGENTS);

	//take one step and update infection
	moveAgent(agentsList, numAgents, undirectedGraph);
	updateInfection(undirectedGraph); 
	
	
	//free memory
	freeAgents(agentsList);
	freeGraph(undirectedGraph);
	return 0;


}
