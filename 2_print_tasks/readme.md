
**Section 1: Explain the technical concept 📘**

In the Linux operating system, every process or application that runs is managed internally by the kernel. The kernel sees these processes as "tasks." To efficiently manage and keep track of these tasks, the kernel uses a circular doubly linked list known as the task list.

Each individual task (or process) is represented within the kernel using a data structure called `struct task_struct`. This structure is defined in `<linux/sched.h>`. The `task_struct` is a comprehensive data structure that's roughly 1.7 Kilobytes in size. It contains all necessary information about a specific process, including but not limited to its state, priority, and context.

Processes in the Linux environment can be in various states, reflecting their current status in the execution cycle. Here are some of the states:

1. `TASK_RUNNING (R)`: The process is either currently executing or is on a run-queue, waiting for its turn to execute.
2. `TASK_INTERRUPTIBLE (S)`: The process is asleep or blocked, meaning it's not executing. However, it can be awakened by signals.
3. `TASK_UNINTERRUPTIBLE (D)`: This is similar to the TASK_INTERRUPTIBLE state, but the crucial difference is that a process in this state will not wake up even if it receives a signal.
4. `__TASK_STOPPED (T)`: The execution of the process has been stopped. This typically happens when the task receives certain signals or if it's being debugged.

**Section 2: Technical interview questions about this topic and answers 🤓**

1. **Question:** What is the `struct task_struct` in the Linux kernel?
   **Answer:** It is a data structure used by the Linux kernel to represent a process or task. It's defined in `<linux/sched.h>` and contains comprehensive information about the process, including its state, priority, and other attributes.

2. **Question:** How does the Linux kernel maintain the list of processes?
   **Answer:** The kernel stores the processes in a circular doubly linked list known as the task list.

3. **Question:** Name the process state in which the process will not wake up even if it receives a signal.
   **Answer:** The state is `TASK_UNINTERRUPTIBLE (D)`.

4. **Question:** How can you find the state of processes in a Linux system from the command line?
   **Answer:** You can use the `ps -el` command to list the processes along with their states.

**Section 3: Explain the concept in simple words for interview preparation 🌟**

Imagine the Linux kernel is like a school teacher who has many students (processes) in her class. She needs a way to keep track of all of them, know what they're currently doing, and manage them effectively. So, she uses a special notebook (the task list) where each student has their own detailed page (the `task_struct`). This page has all the information about the student, like if they're actively answering a question (`TASK_RUNNING`), waiting for their turn (`TASK_INTERRUPTIBLE`), ignoring her even if she calls them (`TASK_UNINTERRUPTIBLE`), or asked to stand outside the class (`__TASK_STOPPED`). And just like a teacher might do a roll call to know the status of every student, you can do something similar on a Linux machine using the `ps -el` command to see what each process is up to.


----

Linux kernel internally refers processes as tasks.  
Kernel stores the list of processes in a circular doubly linked list called the task list.

Each task/process is represented in kernel with struct task_struct (defined in <linux/sched.h>).

This data structure (task_struct) is huge (1.7 Kilobytes) containing all the information about a specific process.

Let's write a module/device driver which reads the circular linked list and prints the following information for us:

	-->	Process Name

	--> Process ID

	--> Process State

Before that, we should know what are the different states a process can be:

	TASK_RUNNING(R): Process is either currently running or on a run-queue waiting to run
	TASK_INTERRUPTIBLE(S): Process is sleeping/blocked. Can be runnable/awaken by a signal
	TASK_UNINTERRUPTIBLE(D): Similar to TASK_INTERRUPTIBLE, but does not wakeup on a signal
	__TASK_STOPPED(T): Process execution has stopped. This happens when the task receives SIGSTOP, SIGTSTP, SIGTTIN or SIGTTOU signal or if it receives any signal while it is being debugged.

You can find the states using ps -el command

