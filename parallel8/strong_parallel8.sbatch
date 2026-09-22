#!/bin/bash
#SBATCH --job-name=matrix
#SBATCH --partition=Mem500
#SBATCH --output=strong_parallel8.out
#SBATCH --error=strong_parallel8.out
#SBATCH --exclusive

echo "Starting strong_parallel8"
echo ""
echo "------ Serial Results ------"
../serial_v1 1000 50 10000000

echo ""
echo "------ parallel_v8 Results ------"
echo ""
echo "		Cores: 1"
time OMP_NUM_THREADS=1 ../parallel_v8 1000 50 10000000
echo "          Cores: 2"
time OMP_NUM_THREADS=2 ../parallel_v8 1000 50 10000000
echo "          Cores: 4"
time OMP_NUM_THREADS=4 ../parallel_v8 1000 50 10000000
echo "          Cores: 8"
time OMP_NUM_THREADS=8 ../parallel_v8 1000 50 10000000
echo "          Cores: 16"
time OMP_NUM_THREADS=16 ../parallel_v8 1000 50 10000000
echo "          Cores: 32"
time OMP_NUM_THREADS=32 ../parallel_v8 1000 50 10000000

echo "------ Serial Results ------"
time ../serial_v1 1000 50 10000000

echo "Ending strong_parallel8"
