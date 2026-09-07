#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=baseCase.out
#SBATCH --error=baseCase.out
#SBATCH --exclusive

echo "Starting ABM"

echo "10 5"
time ../serial_v1 10 5

echo "100 50"
time ../serial_v1 100 50

echo "1000 500"
time ../serial_v1 1000 500 

echo "10000 5000"
time ../serial_v1 10000 5000

echo "100000 50000"
time ../serial_v1 100000 50000

echo "1000000 500000"
time ../serial_v1 1000000 500000

echo "10000000 5000000"
time ../serial_v1 10000000 5000000

echo "100000000 50000000"
time ../serial_v1 100000000 50000000



echo "1 5000"
time ../serial_v1 1 5000

echo "10 5000"
time ../serial_v1 10 5000

echo "100 5000"
time ../serial_v1 100 5000

echo "1000 5000"
time ../serial_v1 1000 5000

echo "10000 5000"
time ../serial_v1 10000 5000

echo "100000 5000"
time ../serial_v1 100000 5000

echo "1000000 5000"
time ../serial_v1 1000000 5000 

echo "10000000 5000"
time ../serial_v1 10000000 5000

echo "100000000 5000"
time ../serial_v1 100000000 5000



echo "100 1"
time ../serial_v1 100 1

echo "100 10"
time ../serial_v1 100 10

echo "100 100"
time ../serial_v1 100 100

echo "100 1000"
time ../serial_v1 100 1000

echo "100 10000"
time ../serial_v1 100 10000

echo "100 100000"
time ../serial_v1 100 100000

echo "100 1000000"
time ../serial_v1 100 1000000

echo "100 10000000"
time ../serial_v1 100 10000000

echo "Finished ABM"
