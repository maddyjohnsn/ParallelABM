#!/bin/bash

# initial serial
gcc mainBaseDays.c state.c agent.c simulate.c -o serial_v1

# initial parallel
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar.c -o parallel_v1

# parallel v2
gcc -fopenmp mainBaseDays.c state.c agent.c simulatePar2.c -o parallel_v2                                                                
