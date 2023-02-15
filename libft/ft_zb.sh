#! /bin/bash


ar=$(uname -a)
cpp=$(grep -c ^processor /proc/cpuinfo)

wall "

#Architecture : $ar
#CPU physical : $cpp
#vCPU : $(nproc --all)
#Memory Usage : $(free -m | awk 'NR==2 {printf("%.0f/%.0fMB (%.2f%%)", $3, $2, $3 * 100 / $2)}')
#Disk Usage : $(df -h | awk '$NF=="/"{printf("%d/%dGB (%s)", $3, $2, $5)}')
#CPU load : $(mpstat | awk 'NR==4{printf("%.2f", 100 - $13)}')%
#Last boot : $(who -b | awk '{print $3" " $4}')
#LVM use : $(lvscan | awk '{if ($1) {print"yes"; exit;} else {print"no"; exit;}}')
#Connections TCP : $(netstat | grep ESTABLISHED | wc -l | awk '{print$1 "ESTABLISHED"}')
"