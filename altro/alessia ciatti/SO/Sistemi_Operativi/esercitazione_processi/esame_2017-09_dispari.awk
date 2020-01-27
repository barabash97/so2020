#!/bin/bash
	{
		flag = 0;
		for(i=2; i<=NF; i++) {
			for(j=i+1; j<=NF; j++){
				if($i==$j)
					flag=1
			}
		}

		if(flag==1)
			ok[NR] = $1
	}


	END {
		for(a in ok) {
				print ok[a]
		}
	}

	GDB