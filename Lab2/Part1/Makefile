
# Suffix Rule
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	gcc -c $*.c

# Creates the output file
lab2a: lab2a.o
	gcc lab2a.o -o lab2a

# Headerfile dependencies
printf.o: stdio.h
pid_t.o: sys/types.h
fork.o: unistd.h
atoi.o: stdlib.h
errno.o: errno.h	

# Removes the o files and the output file
clean:
	rm *.o lab2a
