#include "state.h"
#include "agent.h"
#include "simulate.h"

int main(int argc, char *argv[]){

	//use the right arguments
	int err;
    	if(argc!=4 ) {
        	printf("Missing the first argument:  number of agents to create\n");
        	printf("Missing the second argument:  number of nodes to create\n");
		printf("Missing the third argument:  number of days to simulate\n");
		return 1;
    	}



	int NAGENTS = atoi(argv[1]);
	int NNODES = atoi(argv[2]);
	int DAYS = atoi(argv[3]);

	
	//malloc for dailyinfected rates
	//
	int* dailyInfectedCounts = malloc(DAYS*sizeof(int));


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

	//take steps and update infection


	simulateDay(DAYS, undirectedGraph, NAGENTS, agentsList, dailyInfectedCounts);	
	

	for (int i = 0; i < DAYS; i++) {
 
		
		printf("Day %d: %d infected\n", i, dailyInfectedCounts[i]);
	}	

	printf("%d infected\n",  dailyInfectedCounts[DAYS - 1]);

	//free memory
	free(dailyInfectedCounts);
	freeAgents(agentsList);
	freeGraph(undirectedGraph);
	return 0;


}
