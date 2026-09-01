 // this is not a dynamic graph! this number is used to allocate memory for
 // nodes->neighbors list. 
#define MAX_NEIGHBORS 100
#define MAX_AGENTS 100

// Struct for nodes: each node has an id, a list of its neighbors, a list of agents it holds,
// a list of weights, and how many neighbors it has
struct Node {
    int id;
    int neighbors[MAX_NEIGHBORS];
    int weights[MAX_NEIGHBORS];
    int numNeighbors;
    struct Agent* agentsInNode[MAX_AGENTS];
    int numAgents;
};
// Struct for graphs: each graph has how many nodes it contains  
// and a list of Node addresses in memory 
struct Graph {
    int numNodes;
    struct Node* nodes;
};
