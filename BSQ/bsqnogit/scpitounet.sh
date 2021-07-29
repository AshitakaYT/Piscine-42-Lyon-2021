# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scpitounet.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aucousin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 08:59:27 by aucousin          #+#    #+#              #
#    Updated: 2021/07/27 09:00:50 by aucousin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

clear
echo "\t\t===== test 0 ====="
touch map.txt
perl scripts/map_gen.pl 1 1 2 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "o"
rm map.txt

echo "\n\t\t===== test 4 ====="
touch map.txt
perl scripts/map_gen.pl 1 1 0 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "x"
rm map.txt

echo "\n\t\t===== test 5 ====="
touch map.txt
perl scripts/map_gen.pl 1 0 10 > map.txt
echo "\nton resultat :\n"
./BSQ .

echo "\n\t\t===== test 8 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 20 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
echo "ce test attend une map sans aucun carré"
rm map.txt

echo "\n\t\t===== test 9 ====="
touch map.txt
perl scripts/map_gen.pl 10 10 00 > map.txt
echo "\nton resultat :\n"
./BSQ map.txt
echo "\nresultat attendu :\n"
