#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday
{
	int day;
	int month;
	int year;
	struct list_head list;
};


static LIST_HEAD(birthday_list);

void InsertPerson( int day, int month, int year)
{
	struct birthday *person;

	person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->day = day;
	person->month = month;
	person->year = year;

	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

}

int simple_init(void)
{


  	InsertPerson(13, 6, 1985);
  	InsertPerson(6, 4, 1990);
  	InsertPerson(28, 12, 2000);


  	list_for_each_entry(ptr, &birthday_list, list)
  	{
  		printk(KERN_INFO " Year %d, Month %d, Day %d\n",
  			 ptr->year, ptr->month, ptr->day);
  	}






         return 0;
}

void simple_exit(void) {
  struct  birthday *ptr, *next;

  printk(KERN_INFO "Removing Module\n");


}



module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structures");
MODULE_AUTHOR("HG");
