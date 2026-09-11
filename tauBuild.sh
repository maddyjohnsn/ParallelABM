#!/bin/bash


export TAU_METRICS=TIME,PAPI_TOT_INS,PAPI_L1_DCM
tau_cc.sh -fopenmp -lTAUsh-papi-pthread-openmp mainBaseDaysTau_v2.c simulate_v2.c agent_v2.c state_v2.c -o tauBuild_v2 
tau_cc.sh -fopenmp -lTAUsh-papi-pthread-openmp mainBaseDaysTau.c simulate_v2.c agent_v2.c state_v2.c -o tauBuild

