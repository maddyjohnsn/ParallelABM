import networkx as nx
import matplotlib.pyplot as plt
import csv

def readData(filename):

	nodesInfectionRates = {}
	edges = []
	with open(filename, "r") as file:
		next(file)
		for line in file:

			lineParts = line.strip().split(";")

			nodeData = lineParts[0].strip("()")
			nodeID, infectionRate = nodeData.split(",")
			nodeID = int(nodeID.strip())
			infectionRate = float(infectionRate.strip())

			nodesInfectionRates[nodeID] = infectionRate
			for i in range(1, len(lineParts)):
				edgeData = lineParts[i].strip("()")
				source, target = edgeData.split(",")
				source = int(source.strip())
				target = int(target.strip())
	
				edges.append((source,target))

	return nodesInfectionRates, edges

nodesInfectionRates, edges = readData("testOutput1step.csv")

def visualize(nodesAndIR, edges):
	graph = nx.Graph()
	graph.add_edges_from(edges)
	pos = nx.spring_layout(graph)
	for i in range(0, len(graph.nodes)):
		graph.nodes[i]["infectionRate"] = nodesAndIR[i]

	infection = [graph.nodes[node]["infectionRate"] for node in graph.nodes]
 
	nx.draw(
		graph,
		node_color = infection,
		node_size=500,
		cmap=plt.cm.Reds,
		vmin=0,
		vmax=1,
		edge_color = "gray",
		width = 2,
		with_labels = True,
		font_size = 12,
		font_weight = "bold")
	plt.colorbar(
	plt.cm.ScalarMappable(cmap=plt.cm.Reds, norm=plt.Normalize(0, 1)),label="Infection rate",shrink=0.7
	)
	plt.savefig("infection_graph.png")


visualize(nodesInfectionRates, edges)






print(nodesInfectionRates)
print()	
print(edges)
		
