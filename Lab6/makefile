
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


all: threadSync2 threadSync

threadSync: threadSync.c
	gcc -o threadSync threadSync.c -l pthread -Wall -Werror

threadSync2: threadSync.c
	gcc -o threadSync2 threadSync2.c -l pthread -Wall -Werror

clean:
	rm threadSync threadSync2