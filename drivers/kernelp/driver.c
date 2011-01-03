#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Tsuibin");
MODULE_DESCRIPTION("module example ");
MODULE_LICENSE("GPL");

		int __init
akae_init (void)
{
//设备的初始化
		printk ("Hello , world\n");
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
