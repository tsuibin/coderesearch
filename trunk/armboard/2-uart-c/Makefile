all:
	#windows
	armasm start.s -o start.o #汇编启动文件
	armcc -c led.c -o led.o
	# -first 指定程序从哪个地方开始执行
	# -entry 指定c程序入口函数(ADS使用的参数) -ro-base 指定烧写位置
	armlink -first start.o -entry mymain -ro-base 0x0 start.o led.o -o led.axf
	#将axf文件转换为二进制文件
	fromeelf -bin led.axf -o led.bin
	#反汇编二进制文件
	fromeelf -c led.axf -o led.txt
	
	#位置无关代码 动态加载执行 一般用在动态库
	#当你的程序里面没有出现全局变量的时候 就是位置无关的代码

	#linux
	#编译出目标文件
	#arm-linux-cc led.c -o led.axf
	#链接目标文件
	#arm-linux-objcopy -O binary -S elf_file bin_file
	#arm-linux-objcopy -bin led.axf  led.bin
