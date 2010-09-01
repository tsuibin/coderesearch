all:	 client server 


%:	%.c
	gcc -Wall -o $@ $<


code%:	source/client%.c source/server%.c
	cp source/client$*.c client.c
	cp source/server$*.c server.c


clean:
	rm -f client server 

