#!/bin/bash
#SBATCH --job-name=matrix
#SBATCH --partition=Mem500
#SBATCH --output=tauEXP.out
#SBATCH --error=tauEXP.out
#SBATCH --exclusive

echo "Starting tauEXP"

export TAU_METRICS=TIME,PAPI_TOT_INS,PAPI_L1_DCM

mkdir -p results

toRun=(tauBuild_v2 tauBuild)

for RUN in "${toRun[@]}";  do

	./$RUN 1000 50 10000
        RESULTDIR="results/${RUN}"
        mkdir -p "$RESULTDIR"
        mv MULTI__* "$RESULTDIR"/
done


echo "Finished tauEXP"
