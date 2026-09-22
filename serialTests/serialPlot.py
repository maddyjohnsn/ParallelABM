import re
import matplotlib.pyplot as plt

FILENAME = "serial.out"
FILENAME2 = "serialNPrint.out"

time = []
time2 = []
size = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000 , 1000000]

with open(FILENAME) as f:
   text = f.read()

with open(FILENAME2) as f:
   text2 = f.read()

#parsing for words I want
real_matches = re.findall(r"real\s+(\d+)m([\d.]+)s", text)
real_matches2 = re.findall(r"real\s+(\d+)m([\d.]+)s", text2)

for minutes, seconds in real_matches:
    t = int(minutes) * 60 + float(seconds)
    time.append(t)


for minutes, seconds in real_matches2:
    t = int(minutes) * 60 + float(seconds)
    time2.append(t)

print(time)
print(time2)





print(size)


#plot

plt.figure(figsize=(8, 6))
plt.plot(size, time, label = "Debugging")
plt.plot(size, time2, label = "No Debugging")
plt.xscale('log')
plt.legend()
plt.xlabel("number of days")
plt.ylabel("Real time (seconds)")
plt.title("1000 agents, 50 nodes, runtime for ABM with No Debugging")
plt.savefig("growingDays2.png", dpi=150)

#plt.show()


