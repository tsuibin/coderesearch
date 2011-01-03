ifneq ($(KERNELRELEASE),) #如果这个宏不是空 那么成立
	obj-m := driver.o

else
KERNELSRC :=/lib/modules/`(uname -r)`/build

modules :
	make -C $(KERNELSRC) SUBDIRS=$(PWD) $@
#make -C 进入到$(KERNELSRC) 这个目录下执行
clean:
	rm -f *.o *.ko *.mod.c *~

endif
