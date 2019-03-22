#ifndef __CREATENEWACCOUNT_H__
#define __CREATENEWACCOUNT_H__

/************************************************************************
			STRUCTURE DEFINE HERE
************************************************************************/
typedef struct /*__attribute__((__packed__))__*/node
{
        char mobile[10];
        char adhaar[12];
        char name[20];
        char address[100];
        char balance[20];
}banker;

banker bank;

/***********************************************************************
			FUNCTIONS DECLARATION
***********************************************************************/
int create_new_account(int);

int input();

int password(int);

int fd();

#endif

