CC      = gcc
CFLAGS  = -g 

OBJS = get_image.o get_link.o main.o common.o read_file.o\
	search_email.o http_get.o sqlite_op.o

all: main

main:$(OBJS)
	$(CC)  -o $@ $(OBJS) -lsqlite3 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o main 
