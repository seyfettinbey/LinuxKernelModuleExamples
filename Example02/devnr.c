



#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

static int driver_open(struct inode *device_file,struct file *instance){
	printk("dev_nr - open was called!\n");
	return 0;
}

static int driver_close(struct inode *device_file,struct file *instance){
	printk("dev_nr - close  was called!\n");
	return 0;
}
 static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};
#define MYMAJOR  90



static int __init my_init(void) {
	int retval;
	printk("Hello, Module inited\n");
	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);
	if(retval == 0) {
		printk("dev_nr - registered Device number Major: %d, Minor: %d\n", MYMAJOR, 0);
	}
	else if(retval > 0) {
		printk("dev_nr - registered Device number Major: %d, Minor: %d\n", retval>>20, retval&0xfffff);
	}
	else {
		printk("Could not register device number!\n");
		return -1;
	}	

	return 0;
}

static void __exit my_exit(void) {
	unregister_chrdev(MYMAJOR, "my_dev_nr");	
	printk("Goodbye, Module exited\n");
}

module_init(my_init);
module_exit(my_exit);
