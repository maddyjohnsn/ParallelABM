import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# need to change this so that it seperates each chunk of graph data into their own node and edge data to pass to visualize().
def readData(filename):
	dataList = []
	# open file
	with open(filename, "r") as file:
		# skip header
		next(file)
		data = file.read()
		#split into graphs on seperator char
		graphs = data.split("%!")
		
		# loop through each graph
		for graph in graphs:
			# lists for graph data
			nodesInfectionRates = {}
			edges = []
			# loop through lines of each graph
			for line in graph.splitlines():
				# if line is empty, skiiip it
				if not line.strip():
					continue
				lineParts = line.strip().split(";")
				
				# get node data
				nodeData = lineParts[0].strip("()")
				nodeID, infectionRate = nodeData.split(",")
				nodeID = int(nodeID.strip())
				infectionRate = float(infectionRate.strip())
				# add node data to dict
				nodesInfectionRates[nodeID] = infectionRate
				# get edge data
				for i in range(1, len(lineParts)):
					edgeData = lineParts[i].strip("()")
					source, target = edgeData.split(",")
					source = int(source.strip())
					target = int(target.strip())
					# add to edges list
					edges.append((source,target))
				# add node data and edges to data list
				dataList.append((nodesInfectionRates, edges))	
	# return the data			
	return dataList

data = readData("multiDayOutput")

# need to change this so that it looks at multiple graph snapshots and creates animation that shows infection spread. 
def visualize(data):
	
	nodesAndIR, edges = data[0]
	# make graph
	graph = nx.Graph()
	graph.add_edges_from(edges)

	pos = nx.spring_layout(graph, seed = 42)

	fig, ax = plt.subplots()
	
	# make colorbar
	cb = plt.cm.ScalarMappable(
		cmap=plt.cm.Reds,
		norm=plt.Normalize(0, 1)
	)

	plt.colorbar(
		cb,
		ax=ax,
		label="Infection rate",
		shrink=0.7
	)

	# this is a built in function with animation that makes the frame update with new graph data from each day
	def update(frame):
		ax.clear()
		nodesAndIR, edges = data[frame]
		infection = [
			nodesAndIR.get(node, 0.0)
			for node in graph.nodes
		]
 
		nx.draw(
			graph,
			pos = pos,
			ax = ax,
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

		ax.set_title(f"Day {frame}")
	# animation function
	ani = FuncAnimation (
		fig, 
		update,
		frames = len(data),
		interval = 500, 
		repeat = True
	)
	
	# save it
	ani.save("infection.gif", writer="pillow", fps=2)

visualize(data)






		
