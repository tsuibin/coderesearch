/********************************************************
 *  * Function : module example
 *   * Author: asmcos@gmail.com
 *    * Date : 2005-08-24
 *     * $Id: kegui.c,v 1.6 2006/06/22 13:20:50 asmcos Exp $
 *      ********************************************************/


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>     /* copy_to_user,copy_from_user */
#include <linux/cdev.h>
#include <linux/device.h>


#define AKAE_MAJOR   240

MODULE_AUTHOR("Asmcos");
MODULE_DESCRIPTION("module example ");
MODULE_LICENSE("GPL");



int akae_open (struct inode *inode,struct file *filp)
{
	return 0;
}

ssize_t akae_read (struct file *filp, char __user *buf, size_t count,
		loff_t *f_pos)
{
	char *rbuf = "akae read";



	/* rbuf <= 9 */
	if (count>9)
		count = 9;

	copy_to_user (buf,rbuf,count);

	return count;
}

ssize_t akae_write (struct file *filp, const char __user *buf, size_t count,
		loff_t *f_pos)
{
	char wbuf[10];


	/* wbuf = 10 */
	if (count >10)
		count = 10;

	copy_from_user(wbuf,buf,count);

	/* BUG? */
	wbuf[9]= 0;

	printk ("user write:%s\n",wbuf);

	return count;
}


int akae_release (struct inode *inode, struct file *filp)

{
	return 0;
}



struct file_operations akae_fops ={
	.owner   = THIS_MODULE,
	.open    = akae_open,
	.read    = akae_read,
	.write   = akae_write,
	.release = akae_release,
};

static struct cdev akae_cdev;
static struct class *akae_class;
static struct device *device;

int akae_register(struct file_operations *fops)
{
	int ret;
	dev_t dev;


	ret = alloc_chrdev_region(&dev, 0, 1, "akae");
	if (ret < 0)
		return -1;

	cdev_init(&akae_cdev, fops);
	akae_cdev.owner = THIS_MODULE;

	ret = cdev_add (&akae_cdev, dev, 1);

	if(ret)
		return -1;

	akae_class = class_create(THIS_MODULE,"akae");
	device = device_create(akae_class, NULL, dev, NULL,"akae");
	return ret;
}

	int __init
akae_init (void)
{

	int rc;

	printk ("Test char dev\n");

	rc = akae_register(&akae_fops);   
	if (rc == -1)
	{
		printk("register char dev error\n");
		return -1;
	}

	return 0;
}

	void __exit
akae_exit (void)
{
	dev_t dev;

	printk ("module exit\n");
	dev = akae_cdev.dev;

	device_destroy(akae_class, dev);
	cdev_del(&akae_cdev);
	unregister_chrdev_region(dev, 1);
	class_destroy(akae_class);

	return ;
}

module_init(akae_init);
module_exit(akae_exit);
