#!/bin/bash
#SBATCH --job-name=strong_parallel_HailMary
#SBATCH --partition=Mem500
#SBATCH --output=strong_parallel_HailMary.out
#SBATCH --error=strong_parallel_HailMary.out
#SBATCH --exclusive

echo "Starting parallel_HailMary"
echo ""
echo "------ Serial Results ------"
time ../serial_v1 1000 50 20000000

echo ""
echo "------ parallel_HailMary Results (20 million days) ------"
echo ""
echo "		Cores: 1"
time OMP_NUM_THREADS=1 ../parallel_HailMary 1000 50 20000000
echo "          Cores: 2"
time OMP_NUM_THREADS=2 ../parallel_HailMary 1000 50 20000000
echo "          Cores: 4"
time OMP_NUM_THREADS=4 ../parallel_HailMary 1000 50 20000000
echo "          Cores: 8"
time OMP_NUM_THREADS=8 ../parallel_HailMary 1000 50 20000000
echo "          Cores: 16"
time OMP_NUM_THREADS=16 ../parallel_HailMary 1000 50 20000000
echo "          Cores: 32"
time OMP_NUM_THREADS=32 ../parallel_HailMary 1000 50 20000000

echo "Ending strong_parallel6"
