/*********************************************
 * Function: module example
 * Author: asmcos@gmail.com
 * Date: 2005-08-24
 * $Id: kegui.c, v 1.6 2006/06/22 13:20:50 asmcos Exp $
 *********************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/uaccess.h> /* copy_to_user, copy_from_user */
#include <linux/serial_core.h> 
#include <asm/plat-s3c/regs-serial.h> /* 寄存器宏 */ 
#include <asm/io.h> /* readl,readb,writel,writeb */

#define iobase        S3C24XX_VA_UART1
#define UART_ULCON1   iobase
#define UART_UCON1    iobase + 0x04
#define UART_UFCON1   iobase + 0x08
#define UART_UBRDIV1  iobase + 0x28
#define UART_UTXH1    iobase + 0x20
#define UART_URXH1    iobase + 0x24
#define UART_UTRSTAT1 iobase + 0x10

MODULE_AUTHOR("Asmcos");
MODULE_DESCRIPTION("module example ");
MODULE_LICENSE("GPL");

void my_read(void);
void my_write(void);
void ser_init(void);

int __init
serial_init(void)
{
	printk("my serial driver starts at this moment.\n");
	ser_init();
	my_write();
	my_read();

	return 0;
}

void my_read(void)
{
	int state;
	char ch;
	int read_count = 15;

	while(read_count)
	{
		state = readl(UART_UTRSTAT1);
		if((0x01 & state) == 1)
		{
			ch = readb(UART_URXH1);
			printk("%c", ch);
			printk("\n");
			read_count--;
		}
		else
		{
			set_current_state(TASK_INTERRUPTIBLE);
			schedule_timeout(10);
		}

	}
	return;
}

void my_write(void)
{
	int state;
	char *str = "this is my serial test.";
	while(*str != '\0')
	{
		state = readl(UART_UTRSTAT1);
		if((0x02 & state) == 2)
		{
			writeb(*str, UART_UTXH1);
			str++;
		}
	}

	return;
}

void ser_init(void)
{
	/* 8N1 */
	writel(3, UART_ULCON1); //00000011

	/* poll mode */
	writel(5, UART_UCON1); //00000101

	/* 115200 */
	writel(26, UART_UBRDIV1);

	/* 关FIFO */
	writel(0, UART_UFCON1); //00000000

	return;
}

void __exit
serial_exit(void)
{
	printk("module exit\n");
	return;
}

module_init(serial_init);
module_exit(serial_exit);
