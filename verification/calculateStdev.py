import statistics
with open("numInfectedAtEnd.txt", "r") as dataFile:
	infectionsAtEnd = []
	# read and clean data
	for line in dataFile:
		clean_line = line.strip()
		clean_line = int(clean_line)
		infectionsAtEnd.append(clean_line)
	
	stdev = statistics.stdev(infectionsAtEnd)
	mean  = statistics.mean(infectionsAtEnd)
	print("infectionsAtEnd: ", infectionsAtEnd)
	print("Mean, Stdev below:")
	print(mean, stdev)
