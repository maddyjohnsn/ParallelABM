#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=parallel5.out
#SBATCH --error=parallel5.out
#SBATCH --exclusive

echo "Starting parallel5"

echo ""

echo "-------- 10000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v5 1000 50 10000


echo ""

echo "-------- 100000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 100000
echo ""
echo "PARALLELL RESULTS"
time ../parallel_v5 1000 50 100000

echo ""


echo "-------- 1000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v5 1000 50 1000000


echo ""

echo "-------- 10000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v5 1000 50 10000000


echo ""
echo "Finished Parallel3"

