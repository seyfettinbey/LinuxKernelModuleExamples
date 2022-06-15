#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int __init my_init(void) {
	printk("Hello, Module inited\n");
	return 0;
}

static void __exit my_exit(void) {
	printk("Goodbye, Module exited\n");
}

module_init(my_init);
module_exit(my_exit);
