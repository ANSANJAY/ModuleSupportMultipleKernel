#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <generated/utsrelease.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");

static int __init kernel_version_init(void) 
{
	//Now depends on our Kernel version we could log a diffrent comment in the Kernel log
	#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 10)
		printk(KERN_INFO "KERNELVERSION: Hello OLD Kernel %s\n", UTS_RELEASE);
	#elif  LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
		printk(KERN_INFO "KERNELVERSION: Hello NEW Kernel %s\n", UTS_RELEASE);
	#else
		printk(KERN_INFO "KERNELVERSION: Hello Moderate Kernel %s\n", UTS_RELEASE);
	#endif
	return 0;
}


static void __exit kernel_version_exit(void)
{
	printk(KERN_INFO "KERNELVERSION: GoodBye.\n");
}

module_init(kernel_version_init);
module_exit(kernel_version_exit);
