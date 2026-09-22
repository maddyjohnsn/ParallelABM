import re
import matplotlib.pyplot as plt

FILENAME = "baseCase.out"

time = []
size = []

with open(FILENAME) as f:
   text = f.read()

#parsing for words I want
real_matches = re.findall(r"real\s+(\d+)m([\d.]+)s", text)

for minutes, seconds in real_matches:
    t = int(minutes) * 60 + float(seconds)
    time.append(t)

print(time)


anSet = re.findall(r"(\d+)\s+(\d+)\s+real", text)

for i in anSet:
    size.append(i)


tuples = [f"{a},{b}" for a, b in size]




#plot

plt.bar(tuples[4:8], time[4:8])
plt.yscale('log')
plt.ylabel('Time (seconds) log scale ')
plt.xlabel('Parameter pair (agents, nodes)')
plt.title('Runtime with consistent graph size')

plt.savefig('consistentNodes.png') 

plt.figure()
plt.bar(tuples[8:12], time[8:12])
plt.yscale('log')
plt.ylabel('Time (seconds) log scale')
plt.xlabel('Parameter pair (agents, nodes)')
plt.title('Runtime with consistent agent size')

plt.savefig('consistentAgents.png')
#plt.show()


