#!/bin/bash
#SBATCH --job-name=ABM
#SBATCH --partition=Cpu40
#SBATCH --output=verify.out
#SBATCH --error=verify.out
#SBATCH --exclusive


num_agents=1000
num_nodes=500
num_days=200

echo "Starting Verification"
echo ""

rm numInfectedAtEnd.txt 
echo "-------- SERIAL_V1 RESULTS (everything compared against these..) -------"

./serial_v1 $num_agents $num_nodes $num_days
./serial_v1 $num_agents $num_nodes $num_days
./serial_v1 $num_agents $num_nodes $num_days
./serial_v1 $num_agents $num_nodes $num_days
./serial_v1 $num_agents $num_nodes $num_days
python3 calculateStdev.py
serialResults=$(python3 calculateStdev.py | tail -n 1)
read serialMean serialStdev <<< "$serialResults"


rm numInfectedAtEnd.txt 

echo "-------- PARALELL_V1 RESULTS -------"
./parallel_v1 $num_agents $num_nodes $num_days
./parallel_v1 $num_agents $num_nodes $num_days
./parallel_v1 $num_agents $num_nodes $num_days
./parallel_v1 $num_agents $num_nodes $num_days
./parallel_v1 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt 
echo ""


echo "-------- PARALELL_V2 RESULTS -------"
./parallel_v2 $num_agents $num_nodes $num_days
./parallel_v2 $num_agents $num_nodes $num_days
./parallel_v2 $num_agents $num_nodes $num_days
./parallel_v2 $num_agents $num_nodes $num_days
./parallel_v2 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V3 RESULTS -------"
./parallel_v3 $num_agents $num_nodes $num_days
./parallel_v3 $num_agents $num_nodes $num_days
./parallel_v3 $num_agents $num_nodes $num_days
./parallel_v3 $num_agents $num_nodes $num_days
./parallel_v3 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V4 RESULTS -------"
./parallel_v4 $num_agents $num_nodes $num_days
./parallel_v4 $num_agents $num_nodes $num_days
./parallel_v4 $num_agents $num_nodes $num_days
./parallel_v4 $num_agents $num_nodes $num_days
./parallel_v4 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V5 RESULTS -------"
./parallel_v5 $num_agents $num_nodes $num_days
./parallel_v5 $num_agents $num_nodes $num_days
./parallel_v5 $num_agents $num_nodes $num_days
./parallel_v5 $num_agents $num_nodes $num_days
./parallel_v5 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V6 RESULTS -------"
./parallel_v6 $num_agents $num_nodes $num_days
./parallel_v6 $num_agents $num_nodes $num_days
./parallel_v6 $num_agents $num_nodes $num_days
./parallel_v6 $num_agents $num_nodes $num_days
./parallel_v6 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"


rm numInfectedAtEnd.txt
echo ""

echo "-------- PARALELL_V7 RESULTS -------"
./parallel_v7 $num_agents $num_nodes $num_days
./parallel_v7 $num_agents $num_nodes $num_days
./parallel_v7 $num_agents $num_nodes $num_days
./parallel_v7 $num_agents $num_nodes $num_days
./parallel_v7 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "-------- SERIAL_V1_O3 RESULTS -------"
./serial_v1_O3 $num_agents $num_nodes $num_days
./serial_v1_O3 $num_agents $num_nodes $num_days
./serial_v1_O3 $num_agents $num_nodes $num_days
./serial_v1_O3 $num_agents $num_nodes $num_days
./serial_v1_O3 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""


echo "-------- PARALLEL_V1_O3 RESULTS -------"
./parallel_v1_O3 $num_agents $num_nodes $num_days
./parallel_v1_O3 $num_agents $num_nodes $num_days
./parallel_v1_O3 $num_agents $num_nodes $num_days
./parallel_v1_O3 $num_agents $num_nodes $num_days
./parallel_v1_O3 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""


echo "-------- PARALLEL_V2_O3 RESULTS -------"
./parallel_v2_O3 $num_agents $num_nodes $num_days
./parallel_v2_O3 $num_agents $num_nodes $num_days
./parallel_v2_O3 $num_agents $num_nodes $num_days
./parallel_v2_O3 $num_agents $num_nodes $num_days
./parallel_v2_O3 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""


echo "-------- SERIAL_V2 (graph restructure) RESULTS -------"
./serial_v2 $num_agents $num_nodes $num_days
./serial_v2 $num_agents $num_nodes $num_days
./serial_v2 $num_agents $num_nodes $num_days
./serial_v2 $num_agents $num_nodes $num_days
./serial_v2 $num_agents $num_nodes $num_days
python3 calculateStdev.py
compareResults=$(python3 calculateStdev.py | tail -n 1)
read compareMean compareStdev <<< "$compareResults"
meanDifference=$(awk -v a="$serialMean" -v b="$compareMean" 'BEGIN {print a - b}')
stdevDifference=$(awk -v a="$serialStdev" -v b="$compareStdev" 'BEGIN {print a - b}')
echo "Compare Stdev difference with Serial: $stdevDifference"
echo "Compare Mean difference with Serial: $meanDifference"

rm numInfectedAtEnd.txt
echo ""

echo "Ending Verification"
