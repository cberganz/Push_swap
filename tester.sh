#! /bin/bash

max=0
min=0
test_nb=1000
value_nb=100
min_val=1
max_val=50000
moyenne=0
for i in `seq 1 $test_nb`
do
    arg=`shuf -i $min_val-$max_val -n $value_nb`
    arg=`echo $arg | sed 's/\n/ /g'`
    current=`./push_swap $arg | wc -l`
	echo "Count : " $current
    error=`./push_swap $arg | ./checker_linux $arg`
	echo "Result : " $error
	echo
	moyenne=$(($moyenne+$current))
    if [[ $current -gt $max ]]
    then
        max="$current"
        worst="$arg"
	fi
	if [ $current -lt $min ]
    then
        min="$current"
    fi
done
echo "Max : " $max
echo "Min : " $min
moyenne=$(($moyenne/$i))
echo "Moyenne : " $moyenne
