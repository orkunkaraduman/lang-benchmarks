#!/usr/bin/env bash

dir=`dirname "$0"`
go build -o $dir/split_go $dir/split.go
