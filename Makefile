bank:create_new_account.o login.o main.o start.o
	cc create_new_account.o login.o main.o start.o -o bank
create_new_account:create_new_account.c
	cc -c create_new_account.c
login.o:login.c
	cc -c login.c
main.o:main.c
	cc -c main.c
start.o:start.c
	cc -c start.c
