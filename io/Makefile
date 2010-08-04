all	: feed read fread tread select

feed	: feed.c
	gcc -o feed feed.c

read	: read.c
	gcc -o read read.c

fread	: fread.c
	gcc -o fread fread.c

tread	: tread.c
	gcc -o tread tread.c -lpthread

select	: select.c
	gcc -o select select.c

clean	:
	rm -f *~ feed read fread tread select
