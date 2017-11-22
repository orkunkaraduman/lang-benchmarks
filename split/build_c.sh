#!/usr/bin/env bash

dir=`dirname "$0"`
gcc -o $dir/split.out $dir/split.c
