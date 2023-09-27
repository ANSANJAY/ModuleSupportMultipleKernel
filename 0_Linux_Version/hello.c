#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");
static int __init test_hello_init(void)
{
    pr_info("%s: In init\n", __func__);
    pr_info("LINUX_VERSION_CODE:%u\n", LINUX_VERSION_CODE);
    return 0;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
