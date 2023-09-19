**Section 1: Explain the technical concept 📘**

Kernel threads are a fundamental aspect of Linux kernel operations. They operate solely in kernel mode and don't have user space context or address space like a typical user process.

1. **Kernel Thread**: Unlike typical processes that operate both in user space and kernel space, kernel threads only operate in kernel space. They don’t run any user-space code and are not associated with user processes. They're not created by the usual process creation system calls like `fork()` or `clone()`.

2. **Use**: Kernel threads perform background operations at the kernel level. For instance, they can manage hardware interrupts, handle deferred work, or carry out any kernel-mode operation.

3. **Examples**:
   - `ksoftirqd`: This is a per-CPU kernel thread used for processing softirqs.
   - `kworker`: Manages and processes work queues in the kernel.

4. **Difference between Kernel Thread and User Thread**: Both are represented in the kernel using the `task_struct` structure. However, kernel threads don't have a user space address space. The `mm` member of their `task_struct` is set to NULL, signifying they don't have an associated memory map.

5. **Creating a Kernel Thread**: The kernel offers API functions to facilitate kernel thread creation. The function `kthread_create` is used to define a kernel thread but doesn't immediately run it. If you want to both define and run the thread, you can use `kthread_run`. It's also crucial to manage kernel threads appropriately by stopping them when they're no longer needed using `kthread_stop`.

**Section 2: Technical interview questions about this topic and answers 🤓**

1. **Question**: Describe the main difference between a kernel thread and a user process in Linux.
   **Answer**: While both kernel threads and user processes are represented by a `task_struct` in Linux, the primary difference is in their address spaces. Kernel threads only run in kernel mode and don't have a user space context. The `mm` member of the `task_struct` for kernel threads is set to NULL, indicating no user space memory map.

2. **Question**: Why might one use `kthread_run` instead of `kthread_create`?
   **Answer**: `kthread_run` is a convenience function that both creates a kernel thread and immediately starts its execution. On the other hand, `kthread_create` only defines the thread. After using `kthread_create`, one would need to manually start the thread using `wake_up_process`.

3. **Question**: What is the significance of the `kthread_should_stop` function in kernel thread routines?
   **Answer**: The `kthread_should_stop` function allows a kernel thread function to periodically check whether it should terminate. It's a mechanism to gracefully stop a kernel thread from outside by setting a termination flag, which the kernel thread checks during its operations.

**Section 3: Explain the concept in simple words for interview preparation 🌟**

Imagine the Linux kernel as a factory. Most workers (processes) in this factory can work both inside the main office (user space) and in the production area (kernel space). However, some specialized workers (kernel threads) only work in the production area. These specialized workers don't have a personal office (user space) and were not hired through the typical hiring process (`fork()` or `clone()`). Instead, they were specially recruited (`kthread_create` or `kthread_run`) for specific tasks, like handling machinery (hardware interrupts) or managing deferred work. Just like any worker, it's crucial to tell them when their shift ends (`kthread_stop`) to ensure everything runs smoothly in the factory.


-----

What is  Kernel Thread?
======================================
A Kernel Thread is a Linux Task running only in kernel mode. It is not created by running fork() or clone() system calls.

What is the use of Kernel Thread?
========================================
Kernel Threads helps the kernel to perform operations in background.

What are the some examples of Kernel Thread?
=============================================
1. ksoftirqd is Per CPU kernel thread runs processing softirqd.
2. kworker is a kernel thread which processes work queues.

What are the differences between Kernel Thread and User Thread?
==================================================================
Both Kernel Thread and User Thread are represented by task_struct. The main difference is that there is no address space in kernel threads. mm variable of task_struct is set to NULL.

How to Create a Kernel Thread?
====================================

API For creating a kernel thread.

#include <linux/kthread.h>
struct task_struct *kthread_create(int (*threadfn)(void *data), void *data, const char name[], ...)

Parameters:

threadfn -> the function which thread should run
data -> Argument for thread function
name -> Printf style format for the name of kernel thread.

Return Value: Pointer to struct  task_struct

Note: kthread_create only creates the thread but doesn't run the thread, we need to call wake_up_process() with the return value of kthread_create as an argument to the wake_up_process for the thread function to run.

Linux provides an API which creates the kernel thread and calls wake_up_process().

struct task_struct * kthread_run(int (*threadfn)(void *data), void *data, const char name[], ...)

To stop the kernel thread.

int kthread_stop(struct task_struct *k);

Note: If you don't stop the kernel thread in your module_exit function, you will get oops message.

kthread_stop is a blocking call, it waits until the function executed by thread exits. kthread_stop() flag sets a variable in the task_struct variable which the function running in while(1) should check in each of its loop.

int threadfunc(void *data)
{

     while(!kthread_should_stop())
     {
                //perform operations here
      }
	return 0;
}
