#! /bin/bash

COEFF=(decillion vigintillion trigintillion quadragintillion quinquagintillion sexagintillion septuagintillion octogintillion nonagintillion centillion decicentillion viginticentillion trigintacentillion quadragintacentillion quinquagintacentillion sexagintacentillion septuagintacentillion octogintacentillion nonagintacentillion ducentillion)
PRE=(un duo tres quattuor quin ses sept octo noven)
MID=(deci viginti triginta quadraginta quinquaginta sexaginta septuaginta octoginta nonaginta)

NUMBER="1000000000000000000000000000000000"
OFFSET="000"
SEP=": "

i=0
while [ $i -lt 20 ]; do
	j=-1
	while [ $j -lt 9 ]; do
		if [ $j -lt 0 ]; then
			echo "$NUMBER$SEP${COEFF[$i]}" >> $1
		else
			echo "$NUMBER$SEP${PRE[$j]}${COEFF[$i]}" >> $1
		fi
		NUMBER="$NUMBER$OFFSET"
		((j++))
	done
	((i++))
done
