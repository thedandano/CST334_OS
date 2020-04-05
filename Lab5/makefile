
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


all: first

first: first.c
	gcc -g -o first first.c -Wall -pthread


clean:
	rm  first
