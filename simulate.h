//new struct that needs to have list of agents and a destination for them
typedef struct {
    int agentIndex;
    int destinationNode;
} PendingMove;


//will go through the world updating agent
void updateInfection(struct Graph* graph);

void simulateDay(int days, struct Graph* graph, int numAgents, struct  Agent* agents, int* dailyInfectedCounts);

//void moveAgent(struct Agent* agents, int numAgents, struct Graph* graph);
