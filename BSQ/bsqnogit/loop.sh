make re
w=10
h=10
d=5
i=0
while [ $i -lt $1 ]
do
	touch map.txt
	clear
	perl scripts/map_gen.pl $w $h $d > map.txt
	time ./BSQ map.txt
	i=`expr $i + 1`
	sleep 0.01
	rm map.txt
done
