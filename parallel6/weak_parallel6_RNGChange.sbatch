#!/bin/bash
#SBATCH --job-name=matrix
#SBATCH --partition=Mem500
#SBATCH --output=weak_parallel6_RNGChange.out
#SBATCH --error=weak_parallel6_RNGChange.out
#SBATCH --exclusive

echo "Starting weak_parallel6_RNGChange"
echo ""

echo ""
echo "------ weak_parallel6_RNGChange Results ------"
echo ""
echo "		Cores: 1"
time OMP_NUM_THREADS=1 ../parallel_v6_RNGChange 1000 50 200000
echo "          Cores: 2"
time OMP_NUM_THREADS=2 ../parallel_v6_RNGChange 1000 50 400000
echo "          Cores: 4"
time OMP_NUM_THREADS=4 ../parallel_v6_RNGChange 1000 50 800000
echo "          Cores: 8"
time OMP_NUM_THREADS=8 ../parallel_v6_RNGChange 1000 50 1600000
echo "          Cores: 16"
time OMP_NUM_THREADS=16 ../parallel_v6_RNGChange 1000 50 3200000
echo "          Cores: 32"
time OMP_NUM_THREADS=32 ../parallel_v6_RNGChange 1000 50 6400000

echo "Finished weak_parallel6_RNGChange"
