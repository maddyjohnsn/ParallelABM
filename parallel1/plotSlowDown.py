import re
import matplotlib.pyplot as plt

serial = [0.726, 6.637, 70.248, 699.45]
parallel = [0.721, 7.226, 67.161, 690.125]


size = [1000, 10000, 100000, 1000000]

slowdown = [s / p  for s, p in zip(serial, parallel)]


plt.figure(figsize=(8, 6))
plt.plot(size, slowdown)

plt.xscale('log')

plt.xlabel("problem size")
plt.ylabel("speedup")
plt.title("1000 agents, 50 nodes, speedup for ABM")
plt.savefig("slowDown.png", dpi=150)

