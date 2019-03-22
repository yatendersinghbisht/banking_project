#include"start.h"
#include"login.h"
#include"createnewaccount.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**********************************************************************

  "START" FUNCTION DEFINITION 

 **********************************************************************/

FILE *fp;

int start()
{
			system("clear");
	while(1)
	{
		int fun_ret,z=0,validation=0;
		char choice[4];
		int loop_check1=0;
		choice[0] = '\0';
		choice[1] = '\0';
		choice[2] = -126;
		choice[3] = '\0';
/*		if(z==1)
		{
			getchar();
			p=1;
		}*/

		while(1)
		{	
			fun_ret=0;
			choice[2] = -126;
			if(loop_check1==1)
			{
				getchar();
			}
			printf("\n\n\t\t*******************************\"WELCOME IN BANK\"*******************************\n\n");
			printf("\t\t\t\t\t\t1.LOGIN\n\t\t\t\t\t\t2.CREATE NEW ACCOUNT\n\t\t\t\t\t\t3.FORGOT PASSWORD\n");
			//while(getchar()!='\n');
			fscanf(stdin,"%3[^\n]s",choice);
			for(validation=0;choice[validation];validation++);

			if(validation>2)
			{
				printf("Wrong Input\n");
				scanf("%*[^\n]choice");
				loop_check1=1;
				continue;
			}
			
			if(choice[2] == -126)
			{	loop_check1=1;
				if((choice[0] == 49) || (choice[0] == 50) || (choice[0] == 51))
					break;
				else
					printf("Wrong Input\n");
			}
			else
			{	
				scanf("%*[^\n]choice");
				printf("Invalid entry !!!\n");
				loop_check1=1;
				continue;
			}
			
		}
		loop_check1=1;
		switch(choice[0])
		{
			case '1': fun_ret = login();
				  if(fun_ret!=0 && fun_ret!=1)
				  {

					  printf("Login Error");
				  }
				  z=1;
				  break;

			case '2': fun_ret = create_new_account(loop_check1);
				  if(fun_ret!=0)
				  {

					  printf("Login Error");
				  }
				z=1;
				  break;
			case '3': fun_ret = forgot_password();
 				 if(fun_ret!=0 && fun_ret!=1)
				 {
					printf("Error in function forgot password\n");
				 }
				 z=1;
				 break;
	
			default: printf("\nENTER AGAIN!!!\n");
				 break;
		}
		if(fun_ret==1 || z==1)
		{
			getchar();
		}
		//z=1;
	}
	return 0;
}



/*******************************************************************************

	"FORGOT PASSWORD" FUNCTION DEFINITION HERE

*******************************************************************************/
int forgot_password()
{
	char acc_no0[11],acc_no1[11],mobile_no0[11],mobile_no1[11],passw[20];
	int eof_read=1,counter=0,compare_0=1,compare_1=1,counter_1,counter_2,validation,check,attempt=3;
	
	memset(acc_no0,'\0',sizeof(acc_no0));
	memset(passw,'\0',sizeof(passw));
	memset(acc_no1,'\0',sizeof(acc_no1));
	memset(mobile_no0,'\0',sizeof(mobile_no0));
	memset(mobile_no1,'\0',sizeof(mobile_no1));



	fp=fopen("abc.txt","r+");
	if(fp==NULL)
	{
		printf("There is no records in file. Please first create an account !!!\n");
		return 1;
	}


	do
	{	
		printf("You have only %d attempts to reset your password\n",attempt--);	
	do
	{	
		counter_1=0;
		counter_2=0;
		printf("Please enter your 10 digits account no.\n");
		while(getchar()!='\n');
		scanf("%11[^\n]s",acc_no0);
		//acc_no0[10]='\0';
		for(validation=0;acc_no0[validation];validation++);
		if(validation>10)
		{
			printf("Wrong Input (Input exceeds). \n");
			scanf("%*[^\n]acc_no0");
			//continue;
			counter_2++;
		}
		if(validation<10)
		{
			printf("Wrong Input (too short).\n");
			counter_2++;
		}
		if(validation==10)
		{
			for(check=0;acc_no0[check];check++)
			{
				if(acc_no0[check]<48 || acc_no0[check]>58)
					counter_1++;
			}
		}

	}while(counter_2!=0 || counter_1!=0);


 do
        {
                counter_1=0;
                counter_2=0;
		printf("Please enter your 10 digits mobile no.\n");
		while(getchar()!='\n');
		scanf("%11[^\n]s",mobile_no0);
                //acc_no0[10]='\0';
                for(validation=0;mobile_no0[validation];validation++);
                if(validation>10)
                {
                        printf("Wrong Input (Input exceeds). \n");
                        scanf("%*[^\n]mobile_no0");
                        //continue;
                        counter_2++;
                }
                if(validation<10)
                {
                        printf("Wrong Input (too short).\n");
			counter_2++;
                }
                if(validation==10)
                {
                        for(check=0;acc_no0[check];check++)
                        {
                                if(acc_no0[check]<48 || acc_no0[check]>58)
                                        counter_1++;
                        }
                }

        }while(counter_2!=0 || counter_1!=0);






		while(eof_read!=0)
		{
			eof_read=fread(acc_no1,10,1,fp);
			 acc_no1[10]='\0';
		//	printf("%s",acc_no1);

			fseek(fp,+20,1);
			fread(mobile_no1,10,1,fp);
			 mobile_no1[10]='\0';
		//	 printf("%s",mobile_no1);

			compare_0=strcmp(acc_no0,acc_no1);
			compare_1=strcmp(mobile_no0,mobile_no1);
			if(compare_0==0 && compare_1==0)
			{
				fseek(fp,-30,1);
				fread(passw,sizeof(passw),1,fp);
				passw[19]='\0';

				break;

			}

			else
				fseek(fp,+152,1);
		}

		if(compare_0==0 && compare_1==0)
		{
			printf("Your pasword is %s ",passw);
			fseek(fp,-20,1);
			
			
			password(1);
			break;
		}
		else
		{
			printf("Your Account no. Or Password May be incorrect\n");
			counter++;
		}


	}while(counter<3);
	fclose(fp);
	return 0;
}

