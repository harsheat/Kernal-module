#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched/signal.h>
void dfs(struct task_struct *task)
{
	struct task_struct *next_task;
	struct list_head *head;
	list_for_each(head,&task->children){
		next_task=list_entry(head,struct task_struct,sibling);
		printk(KERN_INFO "PID- %d	pname- %s	state- %ld\n",next_task->pid,next_task->comm,next_task->state);
		dfs(next_task);
	}
}
static int __init entry(void)
{
	printk(KERN_INFO "Loading the module...\n");
	dfs(&init_task);
	printk(KERN_INFO "Loading Complete\n");
	return 0;
}
static void __exit cleanup(void)
{
	printk(KERN_INFO "Module Cleaned\n");
}
module_init(entry);
module_exit(cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PES2UG20CS137");
MODULE_DESCRIPTION("OPERATING SYSTEM PROJECT");

