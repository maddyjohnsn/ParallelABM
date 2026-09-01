
//will go through the world updating agent
//
//

void updateInfection(Agent* agents, int numAgents){

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
        	if (infectedContacts >= 3) {
            		agents[i].isInfected = true;
        	}


	}

}


int main(){


	struct Graph* graph = createGraph(/* however many nodes */);
	//making struct in here?? adding edge???

	//maybe not the right place / way to be doing this come back to it
	Agent* agents = makeAgents(NAGENTS, graph);
	
	if (agents == NULL) {
        	fprintf(stderr, "Failed to allocate agents\n");
        	return 1;
    	}

	//eventually need to free everything
	//free(agents);
	//free(graph->nodes);
	//free(graph);

	return 0;



}
