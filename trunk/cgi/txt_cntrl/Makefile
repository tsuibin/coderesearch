CC = gcc
FLAGS = -g -Wall -lcgi -lsqlite3
CGIBIN = .

all:
	$(CC) $(FLAGS) reset.c txt_cntl.c wrap.c cli.c cgi_op.c -c 
	$(CC) $(FLAGS)  wrap.o  cgi_op.o cli.o txt_cntl.o -o txt_cntrl.cgi
	$(CC) $(FLAGS)  wrap.o  cgi_op.o cli.o reset.o -o reset.cgi
	rm *.o
clean:
	rm *.o

	@echo 
	@echo Example compiled. Now copy multiple.cgi and 
	@echo *.html files to your webserver cgi-bin directory
	@echo To test, call multiple.cgi application
	@echo 
