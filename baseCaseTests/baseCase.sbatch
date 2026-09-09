#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=baseCase.out
#SBATCH --error=baseCase.out
#SBATCH --exclusive

echo "Starting ABM"

rm serial
echo "10 5"
time ../serial_v1 10 5

rm serial
echo "100 50"
time ../serial_v1 100 50

rm serial
echo "1000 500"
time ../serial_v1 1000 500 

rm serial
echo "10000 5000"
time ../serial_v1 10000 5000

rm serial
echo "100000 50000"
time ../serial_v1 100000 50000

rm serial
echo "1000000 500000"
time ../serial_v1 1000000 500000

rm serial
echo "10000000 5000000"
time ../serial_v1 10000000 5000000

rm serial

rm serialOutput
echo "10 5"
time ../serial_v1 10 5

rm serialOutput
echo "100 50"
time ../serial_v1 100 50

rm serialOutput
echo "1000 500"
time ../serial_v1 1000 500 

rm serialOutput
echo "10000 5000"
time ../serial_v1 10000 5000

rm serialOutput
echo "100000 50000"
time ../serial_v1 100000 50000

rm serialOutput
echo "1000000 500000"
time ../serial_v1 1000000 500000

rm serialOutput
echo "10000000 5000000"
time ../serial_v1 10000000 5000000

rm serialOutput
echo "100000000 50000000"
time ../serial_v1 100000000 50000000



rm serial
echo "1 5000"
time ../serial_v1 1 5000

rm serial
echo "10 5000"
time ../serial_v1 10 5000

rm serial
echo "100 5000"
time ../serial_v1 100 5000

rm serial
echo "1000 5000"
time ../serial_v1 1000 5000

rm serial
echo "10000 5000"
time ../serial_v1 10000 5000

rm serial
echo "100000 5000"
time ../serial_v1 100000 5000

rm serial
echo "1000000 5000"
time ../serial_v1 1000000 5000 

rm serial
echo "10000000 5000"
time ../serial_v1 10000000 5000

rm serial

rm serialOutput
echo "1 5000"
time ../serial_v1 1 5000

rm serialOutput
echo "10 5000"
time ../serial_v1 10 5000

rm serialOutput
echo "100 5000"
time ../serial_v1 100 5000

rm serialOutput
echo "1000 5000"
time ../serial_v1 1000 5000

rm serialOutput
echo "10000 5000"
time ../serial_v1 10000 5000

rm serialOutput
echo "100000 5000"
time ../serial_v1 100000 5000

rm serialOutput
echo "1000000 5000"
time ../serial_v1 1000000 5000 

rm serialOutput
echo "10000000 5000"
time ../serial_v1 10000000 5000

rm serialOutput
echo "100000000 5000"
time ../serial_v1 100000000 5000



rm serial
echo "100 1"
time ../serial_v1 100 1

rm serial
echo "100 10"
time ../serial_v1 100 10

rm serial
echo "100 100"
time ../serial_v1 100 100

rm serial
echo "100 1000"
time ../serial_v1 100 1000

rm serial
echo "100 10000"
time ../serial_v1 100 10000

rm serial
echo "100 100000"
time ../serial_v1 100 100000

rm serial
echo "100 1000000"
time ../serial_v1 100 1000000

rm serial
rm serialOutput
echo "100 1"
time ../serial_v1 100 1

rm serialOutput
echo "100 10"
time ../serial_v1 100 10

rm serialOutput
echo "100 100"
time ../serial_v1 100 100

rm serialOutput
echo "100 1000"
time ../serial_v1 100 1000

rm serialOutput
echo "100 10000"
time ../serial_v1 100 10000

rm serialOutput
echo "100 100000"
time ../serial_v1 100 100000

rm serialOutput
echo "100 1000000"
time ../serial_v1 100 1000000

rm serialOutput
echo "100 10000000"
time ../serial_v1 100 10000000

rm serialOutput

echo "Finished ABM"
