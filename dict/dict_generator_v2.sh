#! /bin/bash

PRE=(un duo tres quattuor quin ses sept octo noven)
MID=(deci viginti triginta quadraginta quinquaginta sexaginta septuaginta octoginta nonaginta)
COEFF=(centillion ducentillion trecentillion quadringentillion quingentillion sescentillion septingentillion octingentillion nongentillion millinillion)

NUMBER="1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
OFFSET="000"
SEP=": "

i=0
while [ $i -lt 10 ]; do
	j=-1
	while [ $j -lt 9 ]; do
		k=-1
		while [ $k -lt 9 ]; do
			if [ $j -gt -1 -a $k -gt -1 ]; then
				echo "$NUMBER$SEP${PRE[$k]}${MID[$j]}${COEFF[$i]}" >> $1
			elif [ $j -gt -1 ]; then
				echo "$NUMBER$SEP${MID[$j]}${COEFF[$i]}" >> $1
			elif [ $k -gt -1 ]; then
				echo "$NUMBER$SEP${PRE[$k]}${COEFF[$i]}" >> $1
			else
				echo "$NUMBER$SEP${COEFF[$i]}" >> $1
			fi
			NUMBER="$NUMBER$OFFSET"
			((k++))
		done
		((j++))
	done
	((i++))
done
