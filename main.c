

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
