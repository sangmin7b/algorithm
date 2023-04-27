#!/bin/bash
g++ $1".cpp" -o $1
for((i=1;i<=$2;i++))
do
    ./$1 < "testset/test"$i"" > "testset/out"$i""
    echo "test"$i
    diff "testset/out"$i "testset/ans"$i
done