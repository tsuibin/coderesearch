五子棋作品 使用说明
作者：aka522
E-mail: aka522@foxmail.com
个人主页：http://sns.akaedu.org/home/?868

本程序遵守LGPL版权，您可以随意下载并修改。
欢迎更多Linux编程爱好者及其五子棋爱好者一起参与。
制作更智能的算法。

程序在ubuntu 8.04,ubuntu 10.4,Fedora 12上测试通过。
你需要将Linux kernel配置成Framebuffer模式。（见附录）
在1024x768－16bpp,32bpp均可使用。

1.程序编译
make clean;make

2.程序执行
从图形模式切换到控制台，CTRL+ALT+F1 （切回图形模式，CTRL+ALT+F7）。
sudo ./main
移动鼠标单击即可下棋。

3.程序结束后再次运行
clear
sudo ./main

实现主要功能：
1.人机对战        
2.算法对战
3.确定先手 （具体选择见init_chess.c文件)



附录：
关于 Framebuffer的配置，在ubuntu 10.4，Fedora 12上一般会自动进入Framebuffer模式。
在ubuntu 8.04上需要修改/boot/grub/menu.list，找到其中的 linux /boot/vmlinuz-xxxx 等字样， 在后面添加 vga=0x317 保存后重启计算机。

linux /boot/vmlinuz-2.6.28-15-generic root=UUID=e7b3bdd2-7cdc-4d65-8b38-e6470408a7b0 ro vga=0x317

其中0x317是1024x768-16bpp模式。
文档见 linux kernel 文档里的fb/vesa.txt。



