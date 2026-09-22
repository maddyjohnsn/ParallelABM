#!/bin/bash
#SBATCH --job-name=hailmary
#SBATCH --partition=Mem500
#SBATCH --output=hailMary.out
#SBATCH --error=hailMary.out
#SBATCH --exclusive

echo "Starting parallel_HailMary"


echo "-------- 10000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_HailMary 1000 50 10000

echo ""

echo "-------- 100000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 100000
echo ""
echo "PARALLELL RESULTS"
time ../parallel_HailMary 1000 50 100000

echo ""


echo "-------- 1000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_HailMary 1000 50 1000000

echo ""

echo "-------- 10000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_HailMary 1000 50 10000000

echo ""
echo "Finished parallel_HailMary"


