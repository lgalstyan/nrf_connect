#!/usr/bin/env bash
#
# Copyright (c) 2021 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0

source ${ZEPHYR_BASE}/tests/bsim/sh_common.source

SIMULATION_ID="media_controller"
VERBOSITY_LEVEL=2
EXECUTE_TIMEOUT=20

cd ${BSIM_OUT_PATH}/bin

printf "\n\n======== Running media controller local_player test =========\n\n"

Execute ./bs_${BOARD}_tests_bsim_bluetooth_audio_prj_conf \
  -v=${VERBOSITY_LEVEL} -s=${SIMULATION_ID} -d=0 -testid=media_controller_local_player -rs=23

# Simulation time should be larger than the WAIT_TIME in common.h
Execute ./bs_2G4_phy_v1 -v=${VERBOSITY_LEVEL} -s=${SIMULATION_ID} \
  -D=1 -sim_length=60e6 $@

wait_for_background_jobs

printf "\n\n======== Running media controller remote_player test =========\n\n"

Execute ./bs_${BOARD}_tests_bsim_bluetooth_audio_prj_conf \
  -v=${VERBOSITY_LEVEL} -s=${SIMULATION_ID} -d=0 -testid=media_controller_remote_player -rs=46

Execute ./bs_${BOARD}_tests_bsim_bluetooth_audio_prj_conf \
  -v=${VERBOSITY_LEVEL} -s=${SIMULATION_ID} -d=1 -testid=media_controller_server -rs=23

# Simulation time should be larger than the WAIT_TIME in common.h
Execute ./bs_2G4_phy_v1 -v=${VERBOSITY_LEVEL} -s=${SIMULATION_ID} \
  -D=2 -sim_length=60e6 $@

wait_for_background_jobs
