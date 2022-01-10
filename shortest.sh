#! /bin/bash

min_val=1
max_val=50000
value_nb=100

arg=`shuf -i $min_val-$max_val -n $value_nb`
arg=`echo $arg | sed 's/\n/ /g'`
echo $arg > debug.txt
#./push_swap $arg
./push_swap $arg | wc -l
./push_swap $arg | ./checker_linux $arg
#valgrind --leak-check=full ./push_swap $arg |wc -l
