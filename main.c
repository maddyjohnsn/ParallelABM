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

        freeGraph(undirectedGraph);
        return 0;



}
