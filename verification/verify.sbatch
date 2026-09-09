#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Mem500
#SBATCH --output=verify.out
#SBATCH --error=verify.out
#SBATCH --exclusive


echo "Starting Verification"
echo ""

rm numInfectedAtEnd.txt 
echo "-------- SERIAL_V1 RESULTS (everything compared against these..) -------"

./serial_v1 1000 500 1000
./serial_v1 1000 500 1000
./serial_v1 1000 500 1000
./serial_v1 1000 500 1000
./serial_v1 1000 500 1000
python3 calculateStdev.py
serialResults=$(python3 calculateStdev.py | tail -n 1)
read serialMean serialStdev <<< "$serialResults"


rm numInfectedAtEnd.txt 

echo "-------- PARALELL_V1 RESULTS -------"
./parallel_v1 1000 500 1000
./parallel_v1 1000 500 1000
./parallel_v1 1000 500 1000
./parallel_v1 1000 500 1000
./parallel_v1 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt 
echo ""


echo "-------- PARALELL_V2 RESULTS -------"
./parallel_v2 1000 500 1000
./parallel_v2 1000 500 1000
./parallel_v2 1000 500 1000
./parallel_v2 1000 500 1000
./parallel_v2 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V3 RESULTS -------"
./parallel_v3 1000 500 1000
./parallel_v3 1000 500 1000
./parallel_v3 1000 500 1000
./parallel_v3 1000 500 1000
./parallel_v3 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V4 RESULTS -------"
./parallel_v4 1000 500 1000
./parallel_v4 1000 500 1000
./parallel_v4 1000 500 1000
./parallel_v4 1000 500 1000
./parallel_v4 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V5 RESULTS -------"
./parallel_v5 1000 500 1000
./parallel_v5 1000 500 1000
./parallel_v5 1000 500 1000
./parallel_v5 1000 500 1000
./parallel_v5 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- SERIAL_V1_O3 RESULTS -------"
./serial_v1_O3 1000 500 1000
./serial_v1_O3 1000 500 1000
./serial_v1_O3 1000 500 1000
./serial_v1_O3 1000 500 1000
./serial_v1_O3 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""


echo "-------- PARALLEL_V1_O3 RESULTS -------"
./parallel_v1_O3 1000 500 1000
./parallel_v1_O3 1000 500 1000
./parallel_v1_O3 1000 500 1000
./parallel_v1_O3 1000 500 1000
./parallel_v1_O3 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""


echo "-------- PARALLEL_V2_O3 RESULTS -------"
./parallel_v2_O3 1000 500 1000
./parallel_v2_O3 1000 500 1000
./parallel_v2_O3 1000 500 1000
./parallel_v2_O3 1000 500 1000
./parallel_v2_O3 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""


echo "-------- SERIAL_V2 (graph restructure) RESULTS -------"
./serial_v2 1000 500 1000
./serial_v2 1000 500 1000
./serial_v2 1000 500 1000
./serial_v2 1000 500 1000
./serial_v2 1000 500 1000
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$((serialMean - compareMean))
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "Ending Verification"
