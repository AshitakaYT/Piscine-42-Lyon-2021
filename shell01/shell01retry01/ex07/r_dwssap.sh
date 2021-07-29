cat /etc/passwd | cut -d ':' -f 1 | grep -v '#' | awk 'NR%2==1' | sort -r | rev | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./g' | tr -d '\n'
