CC = gcc
FLAGS = -Wall
CGIBIN = .

all:
	$(CC) $(FLAGS) -lcgi -lsqlite3 yhgl.c cgi_op.c wrap.c -o $(CGIBIN)/yhgl.cgi
	$(CC) $(FLAGS) -lcgi -lsqlite3 chaxun.c -o $(CGIBIN)/chaxun.cgi
	$(CC) $(FLAGS) -lcgi -lsqlite3 login.c -o $(CGIBIN)/login.cgi
	$(CC) $(FLAGS) -lcgi -lsqlite3 shangchuan.c -o $(CGIBIN)/shangchuan.cgi
	$(CC) $(FLAGS) -lcgi -lsqlite3 load.c cgi_op.c wrap.c -o $(CGIBIN)/load.cgi
	$(CC) $(FLAGS) -lcgi -lsqlite3 delete.c cgi_op.c wrap.c -o $(CGIBIN)/delete.cgi
	$(CC) $(FLAGS) -c wrap.c cli.c
	$(CC) $(FLAGS) m_contrl.c -c 
	$(CC) $(FLAGS) wrap.o cli.o m_contrl.o -lcgi -lsqlite3  -o m_contrl.cgi
	$(CC) $(FLAGS) banner.c -lcgi -o $(CGIBIN)/banner.cgi
	gcc -Wall -lcgi -lsqlite3 test.c -o test.cgi
clean:
	rm *.o
