#include"createnewaccount.h"
#include<stdio.h>
#include<time.h>
#include<string.h>
#include"login.h"
#include<stdlib.h>
#include<ctype.h>

int var_fd;
char global_passw[20];
FILE *fp;
/*********************************************************************************************************

  "CREATE_NEW_ACCOUNT" FUNCTION DEFINITION

 *********************************************************************************************************/
int create_new_account(int loop_check1_rec)
{
	int fun_ret=1,passw_ret=1,validation;
	char choice[4];
	choice[0] = '\0';
	choice[1] = '\0';
	choice[2] = -126;
	choice[3] = '\0';


	while(1) 
	{

		choice[2] = -126;
		if(loop_check1_rec==1)
		{
			getchar();
		}
		printf("\n\n\t\t\t\t\t\t1. Saving\n\t\t\t\t\t\t2. Current\n\t\t\t\t\t\t3. Fixed account\n");
		fscanf(stdin,"%2[^\n]s",choice);
		for(validation=0;choice[validation];validation++);
		if(validation>2)
		{
			scanf("%*[^\n]choice");
			loop_check1_rec=1;
			continue;
		}

		if(choice[2] == -126)
		{
			if(choice[0] == 49 || choice[0] == 50 || choice[0] == 51)
			{
				break;
			}
			else
				printf("Invalid entry\n");
		}
		else 
		{
			scanf("%*[^\n]s");
			printf("Invalid entry !!!\n");
			loop_check1_rec=1;
			continue;
		}
	}

	switch(choice[0])
	{
		case '1': fun_ret=input();
			  if(fun_ret!=0 && fun_ret!=7)
			  {
				  printf("Input Error");
				  return fun_ret;
			  }
			  if(fun_ret==7)
				  return 0;
			  break;

		case '2': fun_ret=input();
			  if(fun_ret!=0 && fun_ret!=7)
			  {
				  printf("Input Error");
				  return fun_ret;
			  }
			  if(fun_ret==7)
				  return 0;
			  break;

		case '3': var_fd=1;
			  fun_ret=input();
			  if(fun_ret==7)
				  return 0;
			  var_fd=0;
			  break;


		default : printf("you enter a wrong option!!!\n");
			  getchar();
	}

	return 0;
}



/**********************************************************************************

  "INPUT" FUNCTION DEFINITION

 **********************************************************************************/
int input()
{

	int validation,count,i=0,fun_ret=0,length,check,ctype_ret=0,integer,address_check,p,counter=0,compare_0=1,eof_read=1;
	float amount;
	char bal[20]={"5000"};
	char info[10],info_1[12];
	fp=fopen("abc.txt","a+");
	if(fp==NULL)
	{
		printf("Error in opening file\n");
		return 2;

	}

	printf("You have only 3 attempts for each entry\n");
	do
	{	
		printf("\n\nEnter your mobile no. :			(Mobile number should be of 10 integers:)\n");
		getchar();
		scanf("%11[^\n]s",bank.mobile);
		for(validation=0;bank.mobile[validation];validation++);
		if(bank.mobile[0]==48)
		{
			printf("Wrong Input\n");
		}	
		if(validation<10)
		{printf("wrong input\n");
			counter++;
		}
		if(validation==10)
		{
			for(check=0;bank.mobile[check];check++)
			{
				if(bank.mobile[check]<47 || bank.mobile[check]>57)
				{					
					validation=0;
					break;
				}
			}
		}
		if(validation>10)
		{printf("Wrong input\n");
			scanf("%*[^\n]bank.mobile");
			counter++;
		}


		if(validation==10 && bank.mobile[0]!=48)	
		{
			rewind(fp);		
			while(eof_read!=0)
			{	
				memset(info,'\0',sizeof(info));
				fseek(fp,+30,1);
				eof_read=fread(info,10,1,fp);
				info[10]='\0';
				//printf("bank.mobile => %s\n",bank.mobile);
				//printf("info => %s\n",info);
				fseek(fp,+152,1);
				if((compare_0=strcmp(bank.mobile,info))==0)
				{
					printf("Mobile number already exist. Please enter a new number !!!\n");
					counter++;
					break;
				}
				//printf("compare_0 => %d\n",compare_0);
			}
		}

		if(counter==3)
			return 7;
	}while((validation>10) || (validation!=10) || (bank.mobile[0]==48) || (compare_0==0));


/****************************************************************************************************************************************/
	eof_read=1;
	compare_0=1;
	counter=0;	
	do
	{
		printf("\n\nEnter your adhaar no. :				(It should be of 12 integers)\n");
		getchar();
		scanf("%13[^\n]s",bank.adhaar);
		for(validation=0;bank.adhaar[validation];validation++);
		if(validation<12)
		{
			printf("wrong input\n");
			counter++;
		}
		if(validation==12)
		{
			for(check=0;bank.adhaar[check];check++)
			{
				if(bank.adhaar[check]<47 || bank.adhaar[check]>57)
				{
					validation=0;
					break;

				}
			}
		}

		if(validation>12)
		{
			scanf("%*[^\n]bank.adhaar");
			counter++;
		}	

		if(validation==12)
		{
	                rewind(fp);
                        while(eof_read!=0)
                        {
                                memset(info,'\0',sizeof(info));
                                fseek(fp,+40,1);
                                eof_read=fread(info_1,12,1,fp);
                                info_1[12]='\0';
                                //printf("bank.adhaar => %s\n",bank.adhaar);
                                //printf("info_1 => %s\n",info_1);
                                fseek(fp,+140,1);
                                if((compare_0=strcmp(bank.adhaar,info_1))==0)
                                {
                                        printf("Aadhar number already exist. Please enter a new number !!!\n");
                                        counter++;
                                        break;
                                }
                                //printf("compare_0 => %d\n",compare_0);
                        }
                }



		if(counter==3)
                        return 7;	
	}while((validation>12) || (validation!=12) || (compare_0==0));

	counter=0;
	do
	{
		memset(bank.name,'\0',sizeof(bank.name));
		printf("\n\nEnter your name :				(Account Holder name must be within 20 Characters & In CAPITAL)\n");
		getchar();
		scanf("%21[^\n]s",bank.name);
		for(validation=0;bank.name[validation];validation++);

		if(validation>=3 && validation<20)
		{
			for(check=0;bank.name[check];check++)
			{
				if((bank.name[check]>64 && bank.name[check]<91) || (bank.name[check]>96 && bank.name[check]<123) || (bank.name[check]==32))
				{
				}
				else
				{	
					printf("Wrong Input\n");
					validation=2;
					counter++;
					break;
				}
			}
		}
		else
		{
			printf("Wrong Input\n");	
			scanf("%*[^\n]bank.name");	
			counter++;
		}
		if(counter==3)
                        return 7;

	}while((validation<=3 && validation<20) || (validation>20) || (bank.name[0]== 32));	

	counter=0;
	do
	{
		memset(bank.address,'\0',sizeof(bank.address));
		address_check=0;
		printf("\n\nEnter your address :				(Address must be within 20 characters)\n");
		getchar();
		scanf("%101[^\n]s",bank.address);

		for(validation=0;bank.address[validation];validation++);
		
		if(validation>100)
		{
			printf("Wrong Input\n");
			scanf("%*[^\n]bank.address");
			counter++;
		}

		if(validation<5)
		{
			printf("Wrong Input\n");
			counter++;
		}
		if(validation>4 && validation<100)
		{
			for(check=0;bank.address[check];check++)
			{
				if((bank.address[check]>47 && bank.address[check]<58) || (bank.address[check]>64 && bank.address[check]<91) || (bank.address[check]>96 && bank.address[check]<123) || (bank.address[check]==32) || (bank.address[check]==47) || (bank.address[check]==45) || (bank.address[check]==44) || (bank.address[check])==40 || (bank.address[check]==41))
				{
				}
				else
				{
					address_check++;
					counter++;
					break;
				}
			}
		}
		if(counter==3)
			return 7;
	}while((validation>100) || (validation<5) || (address_check==1) || (bank.address[0]==32));

	srand((unsigned)time(0));
	long int random_num=1000000000+rand()%9999999999;

	printf("congratulations ur account has created successfully\n");
	printf("your account no. is : %ld\n",random_num);
	fprintf(fp,"%ld",random_num);

	fun_ret=1;
	int passw_ret=password(1);
	if(passw_ret!=0)
	{
		printf("Password Error");
		return 3;
	}
	if(var_fd==1)
	{	



		fun_ret=fd();
		if(fun_ret!=0)
		{

			printf("Error in Fd block");
			return 0;
		}


	

	}
	else
	{
		printf("\nYour account has credited by 5000.00 rs\n");
		memcpy(bank.balance,bal,sizeof(bal));
	}
	fwrite(&bank,sizeof(banker),1,fp);
	system("clear");
	printf("Please note down your account no. and password for further operations\n");
	printf("\t\tCongrats your account successfully created.\n\t\tYour account no. is => %ld\n\t\tYour password is => %s\n\n",random_num,global_passw);
	fclose(fp);
	printf("\tPress enter to continue\n");
	getchar();
	return 0;
}


/*********************************************************************************************

  "PASSWORD" FUNCTION DEFINITION

 *********************************************************************************************/

int password(int rec)//, int rec_pass)
{
        char passw[20],strength_check[4];
        int passw_check=0,loop_check1=0,loop_check2=0;
        int loop_check, validation, check, num_check, num_check1, upp_check, upp_check1, low_check, low_check1, spc_check, spc_check1,a=0,passw_strength=0;
        do
        {
		memset(passw,'\0',sizeof(passw));
                passw_check =0;
                num_check   =0;
                num_check1  =0;
                upp_check   =0;
                upp_check1  =0;
                low_check   =0;
                low_check1  =0;
                spc_check   =0;
                spc_check1  =0;
		loop_check1 =0;
		loop_check2 =0;
                if(loop_check==1 || strength_check[0]=='Y' || rec==1)
                {
                        getchar();
                }
                printf("\n\nenter your password: \n\nPassword must be 1 uppercase , 1 lower case , 1 numeric , 1 special character(space,!,#,$,&,@) and password length willbe 8-20 characters!!\n");
                fscanf(stdin,"%21[^\n]s",passw);
                for(validation=0 ; passw[validation] ; validation++);
                if(validation<8 || validation>20)
                {
                        if(validation<8)
                                printf("Password length is low, please re-type.\n");
                        else
                                printf("You exceeds maximum password size limit.\n");
                }
                else
                {
                        for(check=0;passw[check];check++)
                        {
                                if((passw[check]>47 && passw[check]<59) || (passw[check]>64 && passw[check]<91) || (passw[check]>96 && passw[check]<123) ||(passw[check]==32) || (passw[check]==33) || (passw[check]==35) || (passw[check]==36) || (passw[check]==38) || (passw[check]==64))
                                {
                                }
                                else
                                        passw_check++;
                        }

                        if(passw_check==0)
                        {
                                for(check=0;passw[check];check++)
                                {
                                        if(passw[check]>47 && passw[check]<59)
                                                num_check++;
                                        else
                                        {
                                                num_check1++;
                                        }
                                }

                                for(check=0;passw[check];check++)
                                {
                                        if(passw[check]>64 && passw[check]<91)
                                                upp_check++;
                                        else
                                        {
                                                upp_check1++;
                                        }
                                }

                                for(check=0;passw[check];check++)
                                {
                                        if(passw[check]>96 && passw[check]<123)
                                                low_check++;
                                        else
                                        {
                                                low_check1++;
                                        }
                                }

                                for(check=0;passw[check];check++)
                                {
                                        if((passw[check]==32) || (passw[check]==33) || (passw[check]==35) || (passw[check]==36) || (passw[check]==38) || (passw[check]==64))
                                        {
                                                spc_check++;
                                        }
                                        else
                                        {
                                                spc_check1++;
                                        }
                                }
                        }
                }




                if(num_check==0 || low_check==0 || upp_check==0 || spc_check==0 ||validation<8 || validation>20 || passw_check!=0)
                {
			printf("Please re-type your password\n");
                        scanf("%*[^\n]s");
                        fflush(stdin);
                        loop_check=1;
                }




                if(num_check!=0 && low_check!=0 && upp_check!=0 && spc_check!=0 && validation>7 && validation<20)
                {

                        if(spc_check<6 && low_check<6 && num_check<6 && upp_check<6)
                        {       if(spc_check!=0)
                                {
                                       getchar();
                                }
                                strength_check[0] = '\0';
                                strength_check[1] = '\0';
                                strength_check[2] = -126;
                                strength_check[3] = '\0';
                                while(1)
                                {

                                        strength_check[2] = -126;
                                        if(loop_check2==1 || loop_check1==1)
                                        {
                                                getchar();
                                        }
                                        printf("(Password strength is medium)\nDo you want to re-type your password.(Press \"Y\" for yes and \"N\" for no)\n");
                                        fscanf(stdin,"%2[^\n]s",strength_check);

                                        if(strength_check[2] == -126)
                                        {
                                                if(strength_check[0] == 78 || strength_check[0] == 89 || strength_check[0]==110 || strength_check[0]==121)
                                                {
                                                        if(strength_check[0]==89 || strength_check[0]==121)
                                                        {
                                                                memset(passw,'\0',sizeof(passw));
                                                        }
                                                        break;
                                                }
                                        }
                                        else
					{
                                                scanf("%*[^\n]s");
                                                printf("Wrong input\n");
                                                loop_check2=1;
                                                continue;
                                        }
					if(strength_check[0]!=78 || strength_check[0]!=89 || strength_check[0]!=110 || strength_check[0]!=121)
					{
						printf("Wrong Input\n");
						loop_check1=1;
					}
                                }
                        }
                        else
                        {
           		        	     printf("Password strength is high.\n");
                        	        	strcpy(strength_check,"N");
                        }
                }
        }while(validation<8 || validation>20 || num_check==0 || low_check==0 || upp_check==0 || spc_check==0 || strength_check[0]=='Y' ||strength_check[0]=='y');

        printf("your password is => %s\n",passw);
	fwrite(&passw,sizeof(passw),1,fp);
	memset(global_passw,'\0',sizeof(global_passw));
	strcpy(global_passw,passw);
	return 0;
}
           
                             






/***********************************************************************************

	"FIXED ACCOUNT" DEFINITION HERE

************************************************************************************/

int fd()
{
	char cm[20];
	int i=0;
	float deposit_amount;
	int dot=0;
 do

        {
		dot=0;
		memset(cm,'\0',sizeof(cm));
                fflush(stdin);
		printf("Interest rate is 4%% per year\n");

                printf("\n\nenter the amount you want to deposit \n");

		
                getchar();
                scanf("%20[^\n]s",cm);


                if(strlen(cm)<18 && cm[0]!=48)
                {
                        for(i=0;cm[i];i++)
                        {
                                if((cm[i]>47 && cm[i]<58) || cm[i]==46)
                                {

					if(cm[i]==46)
					dot++;
                                }

                                else
                                {
                                        printf("Wrong amount Entered\n");


                                        break;
                                }
                        }


                        if(i==strlen(cm) && dot<2)
                        {
				 printf("Your deposited amount is %s\n",cm);
                                deposit_amount=atof(cm);
				deposit_amount+=deposit_amount*4/100;
				sprintf(cm,"%f",deposit_amount);
				strcpy(bank.balance,cm);
				
				printf("After a year your amount will be: %f\n",deposit_amount);
                                break;
                        }
                        else{

                                scanf("%*[^\n]cm");
                                getchar();
 	                    }
                }
                else{
                        printf("Wrong amount entered\n");
                        scanf("%*[^\n]cm");
                }
        }while(1);
	return 0;
}











