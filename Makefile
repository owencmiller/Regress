# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -pedantic

default: main

main: main.o matrix.o neural.o
	$(CC) $(CFLAGS) -o main main.o matrix.o neural.o

neural.o: ./neural/neural.c ./neural/neural.h ./linear/linear.h
	$(CC) $(CFLAGS) -c ./neural/neural.c

matrix.o: ./linear/matrix.c ./linear/matrix.h
	$(CC) $(CFLAGS) -c ./linear/matrix.c

main.o: main.c ./linear/linear.h ./neural/neural.h
	$(CC) $(CFLAGS) -c  main.c


clean:
	rm main main.o matrix.o neural.o
