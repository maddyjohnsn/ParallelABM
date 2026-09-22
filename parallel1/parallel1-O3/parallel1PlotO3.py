import re
import matplotlib.pyplot as plt

FILENAME = "../parallel1.out"
FILENAME2 = "parallel1_03.out"

time = []
time2 = []
size = [1000, 10000, 100000, 1000000]

with open(FILENAME) as f:
   text = f.read()

#parsing for words I want
real_matches = re.findall(r"real\s+(\d+)m([\d.]+)s", text)

for minutes, seconds in real_matches:
    t = int(minutes) * 60 + float(seconds)
    time.append(t)



print(time)


with open(FILENAME2) as f:
   text = f.read()

#parsing for words I want
real_matches = re.findall(r"real\s+(\d+)m([\d.]+)s", text)

for minutes, seconds in real_matches:
    t = int(minutes) * 60 + float(seconds)
    time2.append(t)


parallel = []
serial = []

parallel2 = []
serial2 = []

print(size)


slowdown = []
for i in range(0,8,2):
    slowdown.append(time[i]/time[i+1])
    serial.append(time[i])
    parallel.append(time[i+1])


slowdown2 = []
for i in range(0,8,2):
    slowdown2.append(time2[i]/time2[i+1])
    serial2.append(time2[i])
    parallel2.append(time2[i+1])

slowdown03Serial = []
for i in range(len(serial)):
    slowdown03Serial.append(serial[i]/parallel2[i])

#plot



plt.figure(figsize=(8, 6))
plt.plot(size, serial, label = "serial")
plt.plot(size, parallel, label = "parallel")
plt.plot(size, serial2, label = "serial03")
plt.plot(size, parallel2, label = "parallel03")
plt.xscale('log')
plt.legend()
plt.xlabel("number of days")
plt.ylabel("Real time (seconds)")
plt.title("1000 agents, 50 nodes, runtime for ABM with compiler optimization")
plt.savefig("parallel1O3.png", dpi=150)




plt.figure()
plt.plot(size, slowdown03Serial)
plt.xlabel("number of days")
plt.ylabel("speedup")
plt.title("1000 agents, 50 nodes, runtime for ABM optimized parallel vs serial")
plt.savefig("parallel103Speedup.png", dpi=150)

#plt.show()

