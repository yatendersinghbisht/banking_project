#include"login.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


/************************************************************************************

  "Printing Passbook" FUNCTION DEFINITION

 ************************************************************************************/
FILE *fp;
int print(char account_no[10],int loop_check1_rec)
{
	if(loop_check1_rec==1)
	{
		getchar();
	}
	/*typedef struct node1
	{
		char timer[25];
		char amount[20];
		char total[20];
		char previous[20];


	}d;
	d d2;*/

			system("clear");
	float balance;
	int check_EOF,compare;
	char account[10];
	FILE *print_fp;
	char timer[25];
	char amount[20];
	char total[20];
	char previous[20];
	print_fp=fopen("print.txt","r");
	if(print_fp==NULL)
	{
		printf("Data not found\n");
		return 1;	
	}
	memset(account,'\0',11);
	printf("-------------------------------------\"PASSBOOK PRINTING\"---------------------------------\n\n\n");	
	do
	{	 memset(amount,'\0',20); 
	         memset(total,'\0',20);
		 memset(timer,'\0',25);
		 memset(previous,'\0',20);

		check_EOF=fread(account,10,1,print_fp);
		if((compare=strcmp(account_no,account))==0)
		{
			fread(timer,sizeof(timer),1,print_fp);
			printf("Time & Date !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!=> %s\n",timer);
			fread(amount,sizeof(amount),1,print_fp);
			fread(total,sizeof(total),1,print_fp);
			fread(previous,sizeof(previous),1,print_fp);
			timer[25]='\0';
			amount[20]='\0';
			total[20]='\0';
			previous[20]='\0';
			if(atof(total)>atof(previous))
			{	
				printf("\t\t\tcredited amount on date		=> %s\n\n",amount);
				printf("\t\t\ttotal balance till date 	=> %s\n\n",total);
			}
			else
			{
				printf("\t\t\tDebited Amount 	on date		=> %s\n\n\n",amount);
				printf("\t\t\ttotal balance till date 	=> %s\n\n\n\n\n",total);
			}

			memset(account,'\0',sizeof(account));
		}
		else
			fseek(print_fp,85,1);
	}while(check_EOF!=0);
	 loop_check1_rec=0;

	fclose(print_fp);



	return 0;
}


/********************************************************************************************

  "Login" FUNCTION DEFINITION

 ********************************************************************************************/

int login()
{
	int count=0,attempt=3,fun_ret,compare_0,compare_1,check_EOF,validation=0,check,validity=0,loop_check=0,loop_check1=0;
	char acc_no0[10],pass0[20],info[20],info_1[100];
	char acc_no1[10],pass1[20],choice[4];
	info[20]='\0';
	acc_no1[10]='\0';
	memset(info_1,'\0',sizeof(info_1));
	memset(info,'\0',sizeof(info));
	memset(acc_no1,'\0',sizeof(acc_no1));
	memset(pass1,'\0',sizeof(pass1));
	fp=fopen("abc.txt","r+");
	if(fp==NULL)
	{
		printf("There is no records on file. Please first create an account !!!\n");
		return 1;
	}
	do
	{	printf("\nYou have %d attempts left\n",attempt--);
		do{
			fflush(stdin);
			printf("Enter your account number\n");
			//		getchar();
			scanf("%11s",acc_no0);
			for(validation=0;acc_no0[validation];validation++);

			if(validation!=10)
				printf("\nPlease re-enter your 10 digit account number!!!\n");
			if(validation>10)
			{
			//	printf("PPlease re-enter your 10 digit account number!!!\n");
				scanf("%*[^\n]acc_no0");
			}
			if(validation==10)
			{
				for(check=0;acc_no0[check];check++)
				{
					if(acc_no0[check]<47 || acc_no0[check]>57)
					{
						printf("please re-enter your 10 digit account number");
						validation=0;
						break;
					}
				}
			}

		}while(validation!=10);	

		loop_check=1;
		do{
			if(loop_check==1)
			{
				getchar();
			}
			printf("Enter your password\n");
			fscanf(stdin,"%20[^\n]s",pass0);
			for(check=0;pass0[check];check++);
			if(check>19 || check<8)
			{
				//printf("check=>: %d\n",check);	
			//	fflush(stdin);
				//memset(pass0,'\0',sizeof(pass0));
				loop_check=1;
				printf("wrong password, minimum limit is 8 and max limit of password is 20 character..\n");
				scanf("%*[^\n]pass0");
			}
		}while(check>19 || check<8);		
		loop_check=0;

		rewind(fp);

		do{	

			check_EOF= fread(acc_no1,10,1,fp);
			fread(pass1,20,1,fp);
			fseek(fp,+162,1);
			compare_0=strcmp(acc_no0,acc_no1);
			compare_1=strcmp(pass0,pass1);
			/*printf("acc_no1=> :%s\n",acc_no1);
			  printf("acc_no0=> :%s\n",acc_no0);
			  printf("pass1=> :%s\n",pass1);
			  printf("pass0=> :%s\n",pass0);
			  printf("compare_0=> :%d\tcompare_1=> :%d\n",compare_0,compare_1);*/
			if (compare_0==0 && compare_1==0)
				break;	
		}while(check_EOF);

		if(compare_0==0 && compare_1==0)
			break;
//		getchar();
		if(check_EOF==0)
		{
			printf("User not found\n");
			//			return 0;

		}
		if((compare_0==0 && compare_1!=0) ||(compare_0!=0 && compare_1==0))

		{
			printf("\nEither you are writing a wrong account number or wrong password\n");
			//count++;
		}
		++count;
		//getchar();
	}while(count!=3);
	if(count==3)
		return 0;


	if((compare_0==0) && (compare_1==0))

	{
		fseek(fp,-162,1);

		fread(info,10,1,fp);
		printf("\nYour mobile number is : %s\n",info);

		fread(info,12,1,fp);
		printf("Your adhaar number is   : %s\n",info);

		fread(info,20,1,fp);
		printf("Account holder name is  : %s\n",info);

		fread(info_1,100,1,fp);
		printf("Your address is 	: %s\n",info_1);

		fread(info,20,1,fp);
		printf("Your balance is 	: %s\n",info);
	}
	/*****************************************************************************************************/


	choice[0] = '\0';
	choice[1] = '\0';
	choice[2] = -126;
	choice[3] = '\0';
	loop_check=1;
	while(1)
	{
	while(1)
	{

		choice[2] = -126;
		if(loop_check1==1 || loop_check==1)
		{
			getchar();
		}
		printf("\n\n1. Credit\n2. Debit\n3. Passbook printing\n4. Exit\n");
	//	while(getchar()!='\n');
		fscanf(stdin,"%3[^\n]s",choice);
		for(validation=0;choice[validation];validation++);
		if(validation>2)
		{
			printf("Wrong Input\n");
			loop_check1=1;
			scanf("%*[^\n]choice");
			continue;
		}
		if(choice[2] == -126)
		{
			if(choice[0] == 49 || choice[0] == 50 || choice[0] == 51 || choice[0]==52)
			{
				break;
			}
			else
				printf("Wrong Input\n");
		}
		else
		{
			printf("Invalid entry !!!\n");
			scanf("%*[^\n]choice");
			loop_check1=1;
			continue;
		}
	}

	
	/****************************************************************************************************/
	switch(choice[0])
	{
		case '1': fun_ret=credit(acc_no0);
			loop_check1=1;
                                loop_check=0;
			  if(fun_ret!=0)
			  {
				  printf("credit Error\n");
			  }
			  break;

		case '2': fun_ret=debit(acc_no0);
			loop_check1=1;
                                loop_check=0;
			  if(fun_ret!=0)
			  {

				  printf("Login Error");
			  }

			  break;
		case '3': fun_ret=print(acc_no1,1);
				loop_check1=0;
				loop_check=0;
			  if(fun_ret!=0)
			  {
				printf("error\n");
			  }
			  break;
		case '4': fclose(fp);
			  //printf("Exit hai\n");	
			  return 0;
			printf("Exit hai\n");       

			 // break;
	}
	}
	
}



/***************************************************************************

  "CREDIT" FUNCTION DEFINITION

 ***************************************************************************/
int credit(char account_no[10])
{
	char timer[25];	
	char buffer_2[20];
	FILE *print_fp;
	double credit_amount,amount;
	char cm[20];
	char account[10];
	char bal[20];
	char bal1[20];
	char amo[20];
	int i=0;
	int dot=0,lent=0,validation;	
	time_t t1;
	memset(account,'\0',sizeof(account));
	memset(buffer_2,'0',sizeof(buffer_2));

	strcpy(account,account_no);

	printf("account no. : %s\n",account);

	memset(bal,'\0',sizeof(bal));
	memset(amo,'\0',sizeof(amo));
	memset(timer,'\0',sizeof(timer));
	memset(bal1,'\0',sizeof(bal1));
	time(&t1);

	strcpy(timer,ctime(&t1));

	do
	{
		memset(cm,'\0',sizeof(cm));	
		dot=0;	
		getchar();
		printf("enter the amount you want to credit \n");
		scanf("%14[^\n]s",cm);
		for(validation=0;cm[validation];validation++);

		//printf("cm lenth => %d", strlen(cm));
		if(validation<14 && validation >0)
		{
			for(i=0;cm[i];i++)
			{
				if((cm[i]>47 && cm[i]<58) || cm[i]==46)
				{
					//printf("i=%d",i);	
					//printf("ok");


					if(cm[0]==48 || cm[0]==46)
					{
						break;
					}
					if(cm[i]==46)
					{
						++dot;

					}

				}
				else
				{
					//printf("value of dot %d",dot);
					printf("Wrong amount Entered1n\n");


					break;
				}		
			}
			
			//printf("validation => %d && i => %d\n",validation,i);
				
			if(cm[0]==48 || cm[0]==46)
			{

				printf("Wrong amount entered\n");
			}

			else if(i==validation && dot<2)
			{
				credit_amount=atof(cm);
				break;
			}
			else
			{
				printf("Wrong amount entered\n");
				scanf("%*[^\n]cm");
			}

		}
		else
		{
			printf("Wrong amount entered2n\n");
			scanf("%*[^\n]cm");
		}



	}while(1);

	fseek(fp,-20,1);
	memset(bal,'\0',sizeof(bal));
	fread(bal,20,1,fp);


	amount=atof(bal);
	amount+=credit_amount;

	print_fp=fopen("print.txt","a+");


	sprintf(bal1,"%f",credit_amount);
	sprintf(amo,"%f",amount);
	fseek(fp,-20,1);
	sprintf(buffer_2,"%f",amount);
	fwrite(buffer_2,sizeof(buffer_2),1,fp);
	printf("your updated balance is: %f",amount);
	fwrite(account,sizeof(account),1,print_fp);
	fwrite(timer,sizeof(timer),1,print_fp);
	fwrite(bal1,sizeof(bal1),1,print_fp);
	fwrite(amo,sizeof(amo),1,print_fp);
	fwrite(bal,sizeof(bal),1,print_fp);



	fclose(print_fp);

	return 0;
}



/*************************************************************************

  "DEBIT" FUNCTION DEFINITION

 *************************************************************************/
int debit(char account_no[10])

{	
	int i=0,validation;
	char timer[25];
	FILE *print_fp;
	double debit_amount,amount;
	char bal[20];
	char dm[20];
	char amo[20];
	char buffer[20];
	char account[10];
	int counter=1;
	time_t t1;
	int dot=0;
	strcpy(account,account_no);
	printf("account : %s\n",account);
	memset(buffer,'\0',sizeof(buffer));
	memset(bal,'\0',sizeof(bal));
	memset(amo,'\0',sizeof(amo));
	memset(timer,'\0',sizeof(timer));
	time(&t1);
	strcpy(timer,ctime(&t1));
	do
	{
		counter=1;
		do
		{
			dot=0;
			fflush(stdin);
			printf("\n\nenter the amount which u want to debit\n");
			getchar();
			scanf("%14[^\n]s",dm);
			for(validation=0;dm[validation];validation++);
			if(validation<14 && validation>0)
			{
				for(i=0;dm[i];i++)
				{
					if((dm[i]>47 && dm[i]<58) || dm[i]==46)
					{
						if(dm[0]==48 || dm[0]==46)
							break;
						if(dm[i]==46)
							++dot;
					}
					else
					{
						printf("Wrong amount entered\n");
						break;
					}
				}
				if(dm[0] == 48 || dm[0] ==46)
					printf("Wrong amount entered\n");
				else if(i==validation && dot<2)
				{
					debit_amount=atof(dm);
					break;
				}
				else
				{
					scanf("%*[^\n]dm");
				}
			}
			else
			{
				printf("Wrong amount entered\n");
				scanf("%*[^\n]dm");
			}
		}while(1);


		fseek(fp,-20,1);
		memset(buffer,'\0',sizeof(buffer));
		fread(buffer,sizeof(buffer),1,fp);

		amount=atof(buffer);
		if(debit_amount>amount)
		{
			printf("Insufficient balance\n");
			counter=0;
		}
		else
		{
			print_fp=fopen("print.txt","a+");
			amount=amount-debit_amount;
			fseek(fp,-20,1);
			sprintf(amo,"%f",amount);
			fwrite(amo,sizeof(amo),1,fp);

			sprintf(bal,"%f",debit_amount);
			fwrite(account,sizeof(account),1,print_fp);
			fwrite(timer,sizeof(timer),1,print_fp);
			fwrite(bal,sizeof(bal),1,print_fp);
			fwrite(amo,sizeof(amo),1,print_fp);
			fwrite(buffer,sizeof(buffer),1,print_fp);
			fclose(print_fp);

			printf("your updated balance is: %f",amount);
		}	
	}while(counter==0);
	return 0;
}

	
































