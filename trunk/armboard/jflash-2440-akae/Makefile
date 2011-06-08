CC    = gcc
CFLAGS =  -O2  -D__LINUX__

all: Jflash-s3c2440

Jflash-s3c2440: jtag.o k9s1208.o pin2440.o ppt.o sjf.o
	$(CC) $(CFLAGS) -o $@ jtag.o k9s1208.o pin2440.o ppt.o sjf.o

clean:
	rm -f *.o Jflash-s3c2440
