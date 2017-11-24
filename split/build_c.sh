#!/usr/bin/env bash

dir=`dirname "$0"`
gcc -o $dir/split_c $dir/split.c
