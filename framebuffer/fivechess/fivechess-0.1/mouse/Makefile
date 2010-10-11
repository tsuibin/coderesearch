CC = gcc -g 

CFLAGS =-I . -Wall -g -DDEBUG

TARGET = main

OBJS =  th_main.o fb.o th_mouse.o draw.o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)	

clean:
	rm $(OBJS) $(TARGET) -f
