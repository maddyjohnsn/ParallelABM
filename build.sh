#!/bin/bash

# initial serial
gcc mainBaseDays.c state.c agent.c simulate.c -o serial_v1

# initial parallel
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar.c -o parallel_v1

# parallel v2
<<<<<<< HEAD
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar2.c -o parallel_v2

# initial serial -03
gcc -O3 mainBaseDays.c state.c agent.c simulate.c -o serial_v1_O3

# initial parallel -03
gcc -fopenmp -O3 mainBaseDays.c state.c agent.c simulatePar.c -o parallel_v1_O3

# parallel v2 -03
gcc -fopenmp -O3 mainBaseDays.c state.c agent.c simulatePar2.c -o parallel_v2_O3                

# serial graph restructure
gcc mainBaseDays_v2.c state_v2.c agent_v2.c simulate_v2.c -o serial_v2                                                                                  
=======
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar2.c -o parallel_v2   
>>>>>>> fed121d (Add parallel 3 and 4)

# parallel v3
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar3.c -o parallel_v3

# parallel v4
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar4.c -o parallel_v4
