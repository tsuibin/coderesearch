CC = gcc -g 

TARGET = main

OBJS = main.o fb.o 

all:$(TARGET)
main.o :main.c 
	$(CC) $(CXXFLAGS) -g -c `pkg-config freetype2 --cflags` $< -o $@



$(TARGET):$(OBJS)

	$(CC) $(CXFLAGS) `pkg-config freetype2 --libs` -lm $^ -o $@


clean:
	rm $(OBJS) $(TARGET) -f
