#include"start.h"
#include"login.h"
#include"createnewaccount.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>




/*************************************************************

		MAIN FUNCTION 

*************************************************************/
int main()
{
	int ret;
//	extern long int random_num=0;
	ret=start();
	/* srand((unsigned)time(0));
        long int random_num=1000000000+rand()%9999999999;*/

	if(ret!=0)
	{
		printf("Starting error\n");
	}
	return 0;
}
