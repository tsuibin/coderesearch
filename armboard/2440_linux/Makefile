#CROSS = arm-none-linux-gnueabi-
CROSS = arm-linux-

all:
	$(CROSS)gcc -c start.s
	$(CROSS)gcc -c -nostdlib led.c
	$(CROSS)ld -Ttext 0x0 -g start.o led.o -o led.elf
	$(CROSS)objcopy -O binary -S led.elf led.bin
	$(CROSS)objdump -D -b binary -m arm led.bin > tmp.s

