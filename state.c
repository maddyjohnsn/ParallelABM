#include <stdio.h>
#include <stdlib.h>
#include "state.h"
#include "agent.h"


// creates a graph structure: initializes a list of lists of neighbors, 
// each list within the list initialized to NULL (no neighbors) 
struct Graph* createGraph(int numNodes) {
	struct Graph* newGraph = malloc(sizeof(struct Graph));
	// make a new graph with numNodes nodes
	newGraph->numNodes = numNodes; 
	
	newGraph->nodes = malloc(numNodes * sizeof(struct Node));

	// loop through and populate graph with nodes, give each node id = i
	// and set their numNeighbors, numAgents, and numInfected to 0
	for (int i = 0; i < numNodes; i++) {
        	newGraph->nodes[i].id = i;
        	newGraph->nodes[i].numNeighbors = 0;
		newGraph->nodes[i].numAgents = 0;
		newGraph->nodes[i].numInfected = 0;
    	}
	return newGraph;
}
// adds an undirectional edge (goes from source to dest and vice versa) between two nodes
void addEdge(struct Graph* graph, int source, int dest, int weight) {

	if (graph->nodes[source].numNeighbors >= MAX_NEIGHBORS || graph->nodes[dest].numNeighbors >= MAX_NEIGHBORS) {
		printf("Nodes cannot exceed %d neighbors\n", MAX_NEIGHBORS);
		exit(EXIT_FAILURE);
		}
	// get the number neighbors src currently has so we can 
	// add to neighbors list at the correct index
	int sourceIndex = graph->nodes[source].numNeighbors;
	// place dest in source's neighbor list
	graph->nodes[source].neighbors[sourceIndex] = dest;
	// place weight in weights list
	graph->nodes[source].weights[sourceIndex] = weight;
	// increment num neighbors for source
	graph->nodes[source].numNeighbors++;


	// do the reverse of above code so graph is not directional	
	int destIndex = graph->nodes[dest].numNeighbors;
	graph->nodes[dest].neighbors[destIndex] = source;
	graph->nodes[dest].weights[destIndex] = weight;
	graph->nodes[dest].numNeighbors++;
}


//adding it to make a ring edge so that we don't have to do the work each time
//takes the graph and 1 weight but in the future we could randomize it!!

void addRingEdges(struct Graph* graph, int weight){
	for(int i = 0; i<graph->numNodes; i++){
		int nextNode = (i+1);
		if (nextNode == graph->numNodes){
			nextNode =0;
		}
		addEdge(graph, i, nextNode, weight);
	}
}


//we could in the future add chords in our ring


// prints each node and its neighbors. rudimentary right now could make nicer later
void showGraph(struct Graph* graph) {
	printf("Vertex:  Adjacency List\n");
	printf("Format: NodeId(numberOfAgents)(numInfected) ---> neighborNode(edgeWeight), neighborNode(edgeWeight), etc.\n");
	// loop through nodes
	for (int i = 0; i < graph->numNodes; i++) {
		// print node id and how many neighbors
        	printf("%d(%d)(%d) ---> ", graph->nodes[i].id, graph->nodes[i].numAgents, graph->nodes[i].numInfected);
		// then print its neighbors
		for (int j = 0; j < graph->nodes[i].numNeighbors; j++) {
        		printf("%d(%d),  ", graph->nodes[i].neighbors[j], graph->nodes[i].weights[j]);
			
        	}
        printf("\n");
    }
}

// add an agent to a given node
void addAgentToNode(struct Graph* graph, int nodeId, struct Agent* agent) {
	// grab the node to add to
	struct Node* node = &graph->nodes[nodeId];
	// get last index based on number of agents
	int indexToInsert = node->numAgents;
	if (indexToInsert >= MAX_AGENTS) {
		printf("Cannot Add Agent: Number of agents in a given node cannot exceed %d agents\n", MAX_AGENTS);
		exit(EXIT_FAILURE);
	}
	// add agent
	node->agentsInNode[indexToInsert] = agent;
	// increment number of agents in node
	node->numAgents++;
 
	// check if agent is infected
	if (agent->isInfected) {
	// if yes, increment numInfected
		node->numInfected++;
	}

	// update currentnode
	agent->currentNode = nodeId; 
}
// remove an agent from a given node
void removeAgentFromNode(struct Graph* graph, int nodeId, struct Agent* agent) {
	
 	// grab the node to remove from
        struct Node* node = &graph->nodes[nodeId];
	if (node->numAgents == 0) {
		printf("Cannot Remove Agent: Node%d does not have any agents", nodeId);
                exit(EXIT_FAILURE);
        }
	
	int idxToRemove = -1; 	
	for (int i = 0; i < node->numAgents; i++) {
		if (node->agentsInNode[i] == agent) {
			idxToRemove = i; 
			break; 
		}
	}
	// if agent not found
	if (idxToRemove == -1) {
	        return;
    	}

	// shift indices after the removed index to the left
	for (int i = idxToRemove; i < node->numAgents - 1; i++) {
		node->agentsInNode[i] = node->agentsInNode[i + 1];
    	}
	//update numAgents
	node->numAgents--;
	
	// check if agent is infected
	if (agent->isInfected) {
        // if yes, decrement numInfected
                node->numInfected--;
        } 

	// set currentNode to -1 upon removal. This will update when added to new node. 
	agent->currentNode = -1;
}
	





void freeGraph(struct Graph* graph) {
    if (graph == NULL) return;
    free(graph->nodes);
    free(graph);
}

