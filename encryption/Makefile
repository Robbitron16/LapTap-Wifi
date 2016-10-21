# Authors:
# Alec Defederico
# Caroline Teicher
# Omkar Brahme
# Robby Marver
# Makefile


### COMPILER
CC = gcc -Wall -g -std=c11

# Main target, the decrypt function.
all: encrypt.o wrapper.o
	$(CC) -o decrypt wrapper.o encrypt.o

# Individual source files.
encrypt.o: encrypt.c encrypt.h
	$(CC) -c encrypt.c

wrapper.o: wrapper.c encrypt.h
	$(CC) -c wrapper.c

# Clean the repo.
clean:
	rm -rf decrypt *.o
