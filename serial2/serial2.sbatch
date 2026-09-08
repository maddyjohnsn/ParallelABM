#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=serial2.out
#SBATCH --error=serial2.out
#SBATCH --exclusive

echo "Starting serial2"


rm serialOutput
rm serial_v2Output

echo "-------- 1000 Days --------"

echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000
echo ""
echo "SERIAL_V2 RESULTS"
time ../serial_v2 1000 50 1000

echo "Verifying Results..."
if diff -q ./serialOutput ./serial_v2Output > /dev/null; then
        echo "Serial and serial_v2 output files are IDENTICAL"
else
        echo "Serial and serial_v2 output files are DIFFERENT"
fi

echo ""

rm serialOutput
rm serial_v2Output

echo "-------- 10000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 10000
echo ""
echo "SERIAL_V2 RESULTS"
time ../serial_v2 1000 50 10000

echo "Verifying Results..."
if diff -q ./serialOutput ./serial_v2Output > /dev/null; then
        echo "Serial and serial_v2 output files are IDENTICAL"
else
        echo "Serial and serial_v2 output files are DIFFERENT"
fi

echo ""


rm serialOutput
rm serial_v2Output

echo "-------- 100000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 100000
echo ""echo "SERIAL_V2 RESULTS"
time ../serial_v2 1000 50 100000

echo "Verifying Results..."
if diff -q ./serialOutput ./serial_v2Output > /dev/null; then
        echo "Serial and serial_v2 output files are IDENTICAL"
else
        echo "Serial and serial_v2 output files are DIFFERENT"
fi

echo ""

rm serialOutput
rm serial_v2Output

echo "-------- 1000000 Days --------"
echo "SERIAL RESULTS"
time ../serial_v1 1000 50 1000000
echo ""
echo "SERIAL_V2 RESULTS"
time ../serial_v2 1000 50 1000000

echo "Verifying Results..."
if diff -q ./serialOutput ./serial_v2Output > /dev/null; then
        echo "Serial and serial_v2 output files are IDENTICAL"
else
        echo "Serial and serial_v2 output files are DIFFERENT"
fi

echo ""
echo "Finished Parallel1"
