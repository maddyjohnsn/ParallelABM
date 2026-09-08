#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=serial.out
#SBATCH --error=serial.out
#SBATCH --exclusive
echo "Starting serial"


rm serialOutput
echo "100"
time ../serial_v1 1000 50 100

rm serialOutput
echo "500"
time ../serial_v1 1000 50 500

rm serialOutput
echo "1000"
time ../serial_v1 1000 50 1000

rm serialOutput
echo "5000"
time ../serial_v1 1000 50 5000

rm serialOutput
echo "10000"
time ../serial_v1 1000 50 10000

rm serialOutput
echo "50000"
time ../serial_v1 1000 50 50000

rm serialOutput
echo "100000"
time ../serial_v1 1000 50 100000

rm serialOutput
echo "500000"
time ../serial_v1 1000 50 500000

rm serialOutput
echo "1000000"
time ../serial_v1 1000 50 1000000

echo "Finished serial"
