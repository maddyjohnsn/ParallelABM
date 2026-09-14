#!/bin/bash
#SBATCH --job-name=weak_hailmary
#SBATCH --partition=Mem500
#SBATCH --output=weak_hailMary.out
#SBATCH --error=weak_hailMary.out
#SBATCH --exclusive

echo "Starting weak_weak_hailMary"
echo ""

echo ""
echo "------ weak_weak_hailMary Results ------"
echo ""
echo "		Cores: 1"
time OMP_NUM_THREADS=1 ../parallel_HailMary 1000 50 200000
echo "          Cores: 2"
time OMP_NUM_THREADS=2 ../parallel_HailMary 1000 50 400000
echo "          Cores: 4"
time OMP_NUM_THREADS=4 ../parallel_HailMary 1000 50 800000
echo "          Cores: 8"
time OMP_NUM_THREADS=8 ../parallel_HailMary 1000 50 1600000
echo "          Cores: 16"
time OMP_NUM_THREADS=16 ../parallel_HailMary 1000 50 3200000
echo "          Cores: 32"
time OMP_NUM_THREADS=32 ../parallel_HailMary 1000 50 6400000

echo "Finished weak_weak_hailMary"
