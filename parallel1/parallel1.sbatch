#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=parallel1.out
#SBATCH --error=parallel1.out
#SBATCH --exclusive

echo "Starting parallel1"


echo "1000"
time ../serial_v1 1000 50 1000


echo "10000"
time ../serial_v1 1000 50 10000


echo "100000"
time ../serial_v1 1000 50 100000


echo "1000000"
time ../serial_v1 1000 50 1000000



echo "1000"
time ../parallel_v1 1000 50 1000


echo "10000"
time ../parallel_v1 1000 50 10000


echo "100000"
time ../parallel_v1 1000 50 100000


echo "1000000"
time ../parallel_v1 1000 50 1000000



echo "Finished Parallel1"
