CC = gcc
FLAGS = -Wall
CGIBIN = .

all:
	$(CC) $(FLAGS) -c wrap.c cli.c
	$(CC) $(FLAGS) -lcgi -lsqlite3 -L./sqlite3.h m_contrl.c -c 
	$(CC) $(FLAGS) wrap.o cli.o m_contrl.o  -lcgi -lsqlite3 -L./sqlite3.h -o m_cntrl.cgi

	@echo 
	@echo Example compiled. Now copy multiple.cgi and 
	@echo *.html files to your webserver cgi-bin directory
	@echo To test, call multiple.cgi application
	@echo 
