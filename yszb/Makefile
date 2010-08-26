ifneq ($(KERNELRELEASE),)

obj-m  := mod.o
else


#KERNELSRC :=/lib/modules/`(uname -r)`/build
KERNELSRC :=/home/akaedu/yszb/akaedu/linux-2.6.28.6


modules :  
	make -C $(KERNELSRC) SUBDIRS=$(PWD) $@

clean:
	rm -f *.o *.ko *.mod.c *~
endif
