#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("");
MODULE_DESCRIPTION("module example ");
MODULE_LICENSE("GPL");

static int count;
module_param(count,int,0);

		int __init
akae_init (void)
{
//设备的初始化
		printk ("Hello , world :%d\n",count);
		return 0;
}
		void __exit
akae_exit (void)
{
		printk ("module exit\n");
		return ;
}

module_init(akae_init);
module_exit(akae_exit);
