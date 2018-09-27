# Lidia Montoya
# Assignment 2 Makefile
# Lab 2 CMPT 360

# add macros 
CC = gcc

q1: q1.c
	$(CC) -o q1 q1.c

q2: q2.c
	$(CC) -o q2 q2.c

q3: q3.c
	$(CC) -o q3 q3.c

q7: q7.c
	$(CC) -o q7 q7.c

shell: shell.c
	$(CC) -o shell shell.c

all: q1 q2 q3 q7 shell

run:
  
	echo "Running q1"
	./q1

	echo "Running q2"
	./q2

	echo "Running q3"
	./q3

	echo "Running q7"
	./q7

	echo "Running shell"
	./shell

clean:
	rm -f *.o q1 q2 q3 q7

