#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=parallel6.out
#SBATCH --error=parallel6.out
#SBATCH --exclusive
<<<<<<< HEAD
=======
#SBATCH --cpus-per-task=6

>>>>>>> 219963d1e90b92673bd1e29046bd64d62a0aeeed

echo "Starting parallel6"


echo "-------- 10000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v6 1000 50 10000

echo ""

echo "-------- 100000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 100000
echo ""
echo "PARALLELL RESULTS"
time ../parallel_v6 1000 50 100000

echo ""


echo "-------- 1000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v6 1000 50 1000000

echo ""

echo "-------- 10000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v6 1000 50 10000000

echo ""
echo "Finished Parallel6"

