#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//will go through the world updating agent
//
//

void updateInfection(struct Agent* agents, int numAgents){

	//want to go through, check how many infection counters an agent had
	//I actually don't think that an agent shoudl become infected in the middle of the day... infections are gradual?? 
	
	for (int i = 0; i < numAgents; i++) {
        	if (agents[i].isInfected) continue;

		int infectedContacts = 0;
        	for (int j = 0; j < numAgents; j++) {
            		if (agents[i].encounters[j] > 0 && agents[j].isInfected) {
                		infectedContacts++;
            		}
        	}

		//want it to be 3 if agent is not predisposed and 2 if yes
        	if (infectedContacts >= 3) {
            		agents[i].isInfected = true;
        
			
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
			if (next > graph->numNodes){
				next = 0;

			}
		}
		//remove agent from node
		removeAgentFromNode(graph, current, agent);
		//add agent to different node
		addAgentToNode(graph, next, agent);
			
	}

}

void simulateDay(struct Graph* graph,int numAgents, struct  Agent* agents){

	//every day we want to move agents x2
	//
	for(int i = 0; i<2; i++){
		moveAgent(agents, numAgents, graph)


	}


}
