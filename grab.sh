#!/bin/bash

data=$( ls | grep lab )

for var in $data
do 
	echo $var
	#cp $var ./lab/
	#rm $var 
done



