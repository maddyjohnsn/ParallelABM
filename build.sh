#!/bin/bash

# initial serial
gcc mainBaseDays.c state.c agent.c simulate.c -o serial_v1

# initial parallel
gcc mainBaseDays.c state.c agent.c simulatePar.c -o parallel_v1
