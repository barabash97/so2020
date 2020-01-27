#!/bin/bash

{
	max = 0;
	min = 9999;
	s = 0;
	flag = false;

	for(i=0; i<=NF; i++) {
		s+=$i
		if($i=30)
			flag = true;
		if($i<min)
			min = $i
		if($i>max)
			max = $i
	}

	MAX[$i] = max
	MIN[$i] = min
}

END {
	for(a in MAX){
		if(flag)
			print a, MAX[a], MIN[a]
	}
}

GDB