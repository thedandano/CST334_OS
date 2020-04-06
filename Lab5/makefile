
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


all: threadHello threadHelloFixed  matrix_multiplication

threadHello: threadHello.c
	gcc -g -o threadHello threadHello.c -Wall -pthread

threadHelloFixed: threadHelloFixed.c
	gcc -g -o threadHelloFixed threadHelloFixed.c -Wall -pthread

matrix_multiplication: matrix_multiplication.c
	gcc -g -o matrix_multiplication matrix_multiplication.c -Wall -pthread

clean:
	rm  threadHello threadHelloFixed matrix_multiplication