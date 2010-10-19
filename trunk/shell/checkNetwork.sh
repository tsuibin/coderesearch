#!/bin/bash
#Checks to see if hosts 192.168.1.100-192.168.1.200 are alive
for n in {100..200}; do
host=192.168.1.$n
ping -c2 $host &>/dev/null
if [ $? = 0 ]; then
echo "$host is UP"
else
echo "$host is DOWN"
fi
done 
