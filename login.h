#ifndef __LOGIN_H__
#define __LOGIN_H__



/*******************************************************
		FUNCTIONS DECLARATION
*******************************************************/

// extern long int random_num;

int login();

int credit(char account_no[]);

int debit(char account_no[]);

void reverse(char buff[],int);

int print(char account_no[],int);
#endif


