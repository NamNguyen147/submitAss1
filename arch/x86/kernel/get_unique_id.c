#include <linux/linkage.h>
#include <linux/uaccess.h>
int unique_id = 1; 
int OutOfNumber = 0; 
asmlinkage long sys_get_unique_id(int* uuid)
{
	int ret =0;
	if(OutOfNumber == 1)
		return -1;
	else
	{	
		ret= put_user(unique_id,uuid);
		if(ret == 0)
		{ 
			unique_id++;
			if(unique_id == 0)
			{
				OutOfNumber = 1;
			}
		}	
		return ret;
	}	
}
 
