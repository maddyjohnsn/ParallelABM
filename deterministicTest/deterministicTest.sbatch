#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=deterministicTest.out
#SBATCH --error=deterministicTest.out
#SBATCH --exclusive

rm serialOutput
rm parallelOutput
echo "Starting serial_v1"

echo "1000"
time ../serial_v1 10 10 10

echo "Ending serial_v1"

echo "Starting paralell_v1"

echo "1000"
time ../parallel_v1 10 10 10

echo "Ending parallel_v1"

echo "verifyingResults"

if diff -q ./serialOutput ./parallelOutput > /dev/null; then
	echo "Serial and parallel output files are IDENTICAL"
else
	echo "Serial and parallel output files are DIFFERENT"
fi
