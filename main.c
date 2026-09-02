#include "state.h"
#include "agent.h"

int main(){


        struct Graph* undirectedGraph = createGraph(8);

        addRingEdges(undirectedGraph, 3);

        Agent* agentsList = makeAgent(20, undirectedGraph);
        addAgentToNode(undirectedGraph, 0, &agentsList[0]);
        showGraph(undirectedGraph);
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
        freeGraph(undirectedGraph);
	for (int i = 0; i < 20; i++) {
		printf("isInfected: %d\n", agentsList[i].isInfected);
	}
        return 0;



}
