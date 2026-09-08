#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
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
		newGraph->nodes[i].numAgents = 0;
		newGraph->nodes[i].numInfected = 0;
    	}
	return newGraph;
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
// this function writes "snapshots" of graph data into a file
// each time it is called it will write the data from the graph at that instant, and either
// append to an existing file or create a new file
void writeData(struct Graph* graph, char *outputFile) {
	// used to check if file exists
	struct stat buffer;
	// init node_file
	FILE *node_file = NULL;
	// if file exists, open in append mode
	if (stat(outputFile, &buffer) == 0) {
                node_file = fopen(outputFile, "a");
                if (node_file == NULL) {
                        perror("Error opening nodes file");
                        return;
                }   
	}
	// check if file exists, if not, open in write mode
	if (stat(outputFile, &buffer) == -1) {	
		node_file = fopen(outputFile, "w");
		if (node_file == NULL) {
			perror("Error opening nodes file");
			return;
		}
	fprintf(node_file, "(nodeID, percentInfected)\n");
	// special character to indicate beginning of data
	fprintf(node_file, "%!\n");
	}

	// Loop through nodes and write to file
	for (int i = 0; i<graph->numNodes; i++) {
		struct Node* node = &graph->nodes[i];
		double percentInfected = 0.0;
		if (node->numAgents > 0) {
			 percentInfected = (double) node->numInfected / (double) node->numAgents;
		}
		fprintf(node_file, "(%d, %.2f);", i, percentInfected);
	
			
		fprintf(node_file, "\n");
	}
	// special character to indicate end  of data
        fprintf(node_file, "%!\n");

	fclose(node_file);
}
