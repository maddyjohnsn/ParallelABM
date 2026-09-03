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

	agentDisposition(agentsList);

        showGraph(undirectedGraph);
	printf("\n\n%d\n\n", NAGENTS);
        for (int i = 0; i < NAGENTS; i++) {
		printf("%d\n", i);
                printf("isInfected: %d  currentNode: %d    disposition: %d\n", agentsList[i].isInfected, agentsList[i].currentNode, agentsList[i].disposition);
		printf("------------check---------------");        
	}
	printf("before nagents redef"); 
	
	printf("after moveagents");
	moveAgent(agentsList, numAgents, undirectedGraph);
	printf("after moveagents");
	updateInfection(undirectedGraph); 
	//removeAgentFromNode(undirectedGraph, 0, &agentsList[0]);
        //showGraph(undirectedGraph);
        //removeAgentFromNode(undirectedGraph, 0, &agentsList[0]);

	
	//here's where we need to start doing day by day

	//step 1: is agent infected at home node?
	//update counter
	//move agents randomly one way or the other around the graph
	//update counter again
	//
	//end day and update infected
	//run 5ever

	// test to see if node infection counter is working
       	showGraph(undirectedGraph); 
        for (int i = 0; i < NAGENTS; i++) {
                printf("isInfected: %d  currentNode: %d\n", agentsList[i].isInfected, agentsList[i].currentNode);
        }   
	freeAgents(agentsList);
	freeGraph(undirectedGraph);
	return 0;


}
