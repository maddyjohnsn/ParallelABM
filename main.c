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

        freeGraph(undirectedGraph);
        return 0;



}
