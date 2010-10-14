CC = gcc -g 

TARGET = main

OBJS = main.o jpeg.o  fb.o style.o search_img.o
all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)  -ljpeg -lm

clean:
	rm $(OBJS) $(TARGET) -f
