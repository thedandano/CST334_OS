
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


all: queue_test fifo

queue_test: queue_test.c
	gcc -o queue_test queue_test.c queue.c node.c -Wall -Werror

fifo: fifo.c
	gcc -o fifo fifo.c queue.c node.c -Wall

debug: fifo.c
	gcc -g -o fifo fifo.c queue.c node.c -Wall

clean:
	rm  queue_test fifo
