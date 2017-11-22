#!/usr/bin/env bash

STARTTIME=$(date +%s)
$@
ENDTIME=$(date +%s)
echo "$(($ENDTIME - $STARTTIME)) seconds to complete this task..."
