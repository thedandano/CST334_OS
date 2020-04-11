
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


all: threadSync

threadSync: threadSync.c
	gcc -g -o threadSync threadSync.c -Wall -pthread

clean:
	rm threadSync