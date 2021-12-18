CC=gcc
AR=ar
FLAGS=-g -Wall

all: reader stringProg

stringProg: main.o txtReader.a
	$(CC) $(FLAGS) -o stringProg main.o txtReader.a
reader: txtReader.a
txtReader.a: stringProg.o
	$(AR) -rcs -o txtReader.a stringProg.o

stringProg.o: stringProg.c stringProg.h
	$(CC) $(FLAGS) -c stringProg.c
main.o: main.c stringProg.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all
clean:
	rm -f *.o *.a stringProg
