#include <stdio.h>
#include <stdlib.h>

// this is not a dynamic graph! this number is used to allocate memory for
// nodes->neighbors list. 
#define MAX_NEIGHBORS 100

// Struct for nodes: each node has an id, a list of its neighbors, and how many neighbors it has
struct Node {
	int id; 
	int neighbors[MAX_NEIGHBORS];
	int numNeighbors;
}; 

// Struct for graphs: each graph has how many nodes it contains 
// and a list of Node addresses in memory
struct Graph {
	int numNodes; 
	struct Node* nodes;
};

// creates a node structure: initializes neighbors to null
struct Node* createNode(int id) {
	struct Node* newNode = malloc(sizeof(struct Node)); 
	newNode->id = id; 
	return newNode;
}

// creates a graph structure: initializes a list of lists of neighbors, 
// each list within the list initialized to NULL (no neighbors) 
struct Graph* createGraph(int numNodes) {
	struct Graph* newGraph = malloc(sizeof(struct Graph));
	// make a new graph with numNodes nodes
	newGraph->numNodes = numNodes; 
	
	newGraph->nodes = malloc(numNodes * sizeof(struct Node));

	// loop through and populate graph with nodes, give each node id = i
	// and set their numNeighbors to 0
	for (int i = 0; i < numNodes; i++) {
        	newGraph->nodes[i].id = i;
        	newGraph->nodes[i].numNeighbors = 0;
    	}
	return newGraph;
}
// !!!! WARNING !!!! addEdge does not currently check that you don't exceed MAX_NEIGHBORS
// so don't do that... shouldn't be a problem unless weird things are happening
// adds an undirectional edge (goes from source to dest and vice versa) between two nodes
void addEdge(struct Graph* graph, int source, int dest) {
	// get the number neighbors src currently has so we can 
	// add to neighbors list at the correct index
	int srcCurrentNumNeighbors = graph->nodes[source].numNeighbors;
	// place dest in source's neighbor list
	graph->nodes[source].neighbors[srcCurrentNumNeighbors] = dest;
	// increment num neighbors for source
	graph->nodes[source].numNeighbors++;


	// do the reverse of above code so graph is not directional	
	int destCurrentNumNeighbors = graph->nodes[dest].numNeighbors;
	graph->nodes[dest].neighbors[destCurrentNumNeighbors] = source;
	
	graph->nodes[dest].numNeighbors++;
}

// prints each node and its neighbors. rudimentary right now could make nicer later
void showGraph(struct Graph* graph) {
	printf("Vertex:  Adjacency List\n");
	// loop through nodes
	for (int i = 0; i < graph->numNodes; i++) {
		// print node id
        	printf("%d ---> ", graph->nodes[i].id);
		// then print its neighbors
		for (int j = 0; j < graph->nodes[i].numNeighbors; j++) {
        		printf("%d -> ", graph->nodes[i].neighbors[j]);
        	}

        printf("NULL\n");
    }
}

int main() {
    // Create a graph with 3 vertices
    struct Graph* undirectedGraph = createGraph(3);

    // Add edges
    addEdge(undirectedGraph, 0, 1);
    addEdge(undirectedGraph, 0, 2);
    addEdge(undirectedGraph, 1, 2);

    showGraph(undirectedGraph);
    return 0;
}

