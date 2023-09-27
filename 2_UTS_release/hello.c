#include <linux/kernel.h>
#include <linux/module.h>
#include <generated/utsrelease.h>

MODULE_LICENSE("GPL");
static int __init test_hello_init(void)
{
    pr_info("UTS_RELEASE:%s\n", UTS_RELEASE);
    return 0;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
