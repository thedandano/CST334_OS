
#Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c


.PHONY: all
all: step1 step2 step3

# Creates the output files
step1: step1.o
	gcc step1.o -o step1

step2: step2.o
	gcc step2.o -o step2

step3: step3.o
	gcc step3.o -o step3

clean: 
	rm *.o step1 step2 step3
