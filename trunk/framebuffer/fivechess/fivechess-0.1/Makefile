CC = gcc -g 

CFLAGS =-I ./include -Wall -g -DDEBUG

TARGET = main

OBJS =  main.o fb.o mouse.o draw.o cpu_chess.o  hum_chess.o   ./aka522/aka522_chess.o  init_chess.o  ./aka522/chess_pattern.o   ./mxcai2010/five.o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)	

clean:
	rm $(OBJS) $(TARGET) -f
