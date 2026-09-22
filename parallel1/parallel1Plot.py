import re
import matplotlib.pyplot as plt

FILENAME = "parallel1.out"

time = []
size = [1000, 10000, 100000, 1000000]

with open(FILENAME) as f:
   text = f.read()

#parsing for words I want
real_matches = re.findall(r"real\s+(\d+)m([\d.]+)s", text)

for minutes, seconds in real_matches:
    t = int(minutes) * 60 + float(seconds)
    time.append(t)



print(time)



parallel = []
serial = []

print(size)

slowdown = []
for i in range(0,8,2):
    slowdown.append(time[i]/time[i+1])
    serial.append(time[i])
    parallel.append(time[i+1])

#plot

print(slowdown)
plt.figure(figsize=(8, 6))
plt.plot(size, serial, label = "serial")
plt.plot(size, parallel, label = "parallel")
plt.xscale('log')
plt.legend()
plt.xlabel("number of days")
plt.ylabel("Real time (seconds)")
plt.title("1000 agents, 50 nodes, runtime for ABM")
plt.savefig("parallel1.png", dpi=150)


plt.figure()
plt.plot(size, slowdown)
plt.legend()
plt.xlabel("number of days")
plt.ylabel("speedup")
plt.title("1000 agents, 50 nodes, runtime for ABM")
plt.savefig("parallel1Speedup.png", dpi=150)

#plt.show()

