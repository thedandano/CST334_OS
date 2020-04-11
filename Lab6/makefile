
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


all: threadSync threadSync2 threadSync3

threadSync: threadSync.c
	gcc -o threadSync threadSync.c -l pthread -Wall -Werror

threadSync2: threadSync2.c
	gcc -o threadSync2 threadSync2.c -l pthread -Wall -Werror

threadSync3: threadSync3.c
	gcc -o threadSync3 threadSync3.c -l pthread -Wall -Werror

clean:
	rm threadSync threadSync2 threadSync3