#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>


extern struct task_struct init_task;
/* performs a depth-first traversal of the list of tasks in the system. */
void traverse(struct task_struct *ptr) {
	struct list_head *list;
	struct task_struct *next;

	thread_group_leader(ptr)
	    printk(KERN_INFO ">>>%s[%d]<<<\n",ptr->comm, ptr->pid);

	list_for_each(list, &ptr->children) {
		next = list_entry(list, struct task_struct, sibling);
		traverse(next);
	}
}

int simple_init(void)
{
  struct task_struct *task;
  struct list_head *list;
  
  struct task_struct *c;

  printk(KERN_INFO "Loading Module\n");

  traverse(&init_task);


  return 0;
}

void simple_exit(void) {
  printk(KERN_INFO "Removing Module\n");
}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Process Module");
MODULE_AUTHOR("SGG");

