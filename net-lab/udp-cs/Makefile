all:	 udpclient udpserver 


udp%:	udp%.c
	gcc -Wall -o $* $<


code%:	source/udpclient%.c source/udpserver%.c
	cp source/udpclient$*.c udpclient.c
	cp source/udpserver$*.c udpserver.c


clean:
	rm -f client server 

