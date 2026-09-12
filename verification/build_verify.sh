#!/bin/bash
CFLAGS="-I.."

# initial serial verify
gcc $CFLAGS mainBaseDays_verify.c ../state.c ../agent.c ../simulate.c -o serial_v1

# initial parallel
gcc $CFLAGS -fopenmp mainBaseDays_verify.c ../state.c ../agent.c ../simulatePar.c -o parallel_v1

# parallel v2
gcc $CFLAGS -fopenmp mainBaseDays_verify.c ../state.c ../agent.c ../simulatePar2.c -o parallel_v2

# parallel v3
gcc $CFLAGS -fopenmp mainBaseDays_verify.c ../state.c ../agent.c ../simulatePar3.c -o parallel_v3

# parallel v4
gcc $CFLAGS -fopenmp mainBaseDays_verify.c ../state.c ../agent.c ../simulatePar4.c -o parallel_v4

# parallel v5 
gcc $CFLAGS -fopenmp mainBaseDays6_verify.c ../state.c ../agent.c ../simulatePar5.c -o parallel_v5

# parallel v6 
gcc $CFLAGS -fopenmp mainBaseDays6_verify.c ../state.c ../agent.c ../simulatePar6.c -o parallel_v6

# parallel v6 RNG Change
gcc $CFLAGS -fopenmp mainBaseDays6_verify.c ../state.c ../agent.c ../simulatePar6RNGChange.c -o parallel_v6_RNGChange

# initial serial -03
gcc $CFLAGS -O3 mainBaseDays_verify.c ../state.c ../agent.c ../simulate.c -o serial_v1_O3

# parallell v7 (parallel 6 with struct reorg)
gcc $CFLAGS -fopenmp mainBaseDays_v2_verify.c ../state_v2.c ../agent_v2.c ../simulatePar6_v2.c -o parallel_v7

# parallell v8 (parallel 6 with struct reorg and -O3 compiler flag)
gcc $CFLAGS -O3 -fopenmp mainBaseDays_v2_verify.c ../state_v2.c ../agent_v2.c ../simulatePar6_v2.c -o parallel_v8

# initial parallel -03
gcc $CFLAGS -fopenmp -O3 mainBaseDays_verify.c ../state.c ../agent.c ../simulatePar.c -o parallel_v1_O3

# parallel v2 -03
gcc $CFLAGS -fopenmp -O3 mainBaseDays_verify.c ../state.c ../agent.c ../simulatePar2.c -o parallel_v2_O3

# serial graph restructure
gcc $CFLAGS mainBaseDays_v2_verify.c ../state_v2.c ../agent_v2.c ../simulate_v2.c -o serial_v2                               
