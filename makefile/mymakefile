#CC      = gcc
#CFLAGS  = -g 

OBJS = hello.o\
	print.o

all: main

main:$(OBJS)
	$(CC)  -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY :clean
clean:
	rm *.o main
