# -c -o 编译为.o文件
gcc hello.c -c -o hello.o
gcc my_printf.c -c -o my_printf.o

# 将两个.o文件合并为一个可执行文件
gcc -o hello hello.o my_printf.o
