CC      = gcc
CFLAGS  = -g 

OBJS = get_link get_image get_email search_email http_get sqlite_op


all: $(OBJS)


sqlite_op:sqlite_op.o
	$(CC)  -o $@ $< -lsqlite3

get_email:get_email.o
	$(CC)  -o $@ $<

http_get:http_get.o
	$(CC)  -o $@ $<

search_email:search_email.o
	$(CC)  -o $@ $<

get_image:get_image.o
	$(CC)  -o $@ $<

get_link:get_link.o
	$(CC)  -o $@ $<
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o $(OBJS) 
