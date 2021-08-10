#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/module.h>

asmlinkage long sys_rt_nice(long pi,long tim)
{
	int flag=0;
	struct task_struct *task;
	if(tim<0)
	{
		printk("Invalid soft time value");
		return 0;
	}
	for_each_process(task)
	{
		if(pi==(long)task->pid)
		{
			flag=1;
			printk("Changed rt_nice value  %s\n",task->comm);
			task->se.rt_nice=tim;
		}
	}
	if(flag==0)
		printk("No such process found\n");

	printk("AMIRMNOOHI");
    
	return 0;
}