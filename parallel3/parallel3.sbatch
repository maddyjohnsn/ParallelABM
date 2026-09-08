#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=parallel3.out
#SBATCH --error=parallel3.out
#SBATCH --exclusive

echo "Starting parallel3"


rm serialOutput
rm parallelOutput

echo "-------- 1000 Days --------"

echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v3 1000 50 1000

echo "Verifying Results..."
if diff -q ./serialOutput ./parallelOutput > /dev/null; then
        echo "Serial and parallel output files are IDENTICAL"
else
        echo "Serial and parallel output files are DIFFERENT"
fi

echo ""

rm serialOutput
rm parallelOutput

echo "-------- 10000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v3 1000 50 10000

echo "Verifying Results..."
if diff -q ./serialOutput ./parallelOutput > /dev/null; then
        echo "Serial and parallel output files are IDENTICAL"
else
        echo "Serial and parallel output files are DIFFERENT"
fi

echo ""


rm serialOutput
rm parallelOutput


echo "-------- 100000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 100000
echo ""
echo "PARALLELL RESULTS"
time ../parallel_v3 1000 50 100000

echo "Verifying Results..."
if diff -q ./serialOutput ./parallelOutput > /dev/null; then
        echo "Serial and parallel output files are IDENTICAL"
else
        echo "Serial and parallel output files are DIFFERENT"
fi

echo ""

rm serialOutput
rm parallelOutput

echo "-------- 1000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000000
echo ""
echo "PARALLEL RESULTS"
time ../parallel_v3 1000 50 1000000

echo "Verifying Results..."
if diff -q ./serialOutput ./parallelOutput > /dev/null; then
        echo "Serial and parallel output files are IDENTICAL"
else
        echo "Serial and parallel output files are DIFFERENT"
fi

echo ""
echo "Finished Parallel3"

