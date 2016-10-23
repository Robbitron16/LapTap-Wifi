# Authors:
# Alec Defederico
# Caroline Teicher
# Omkar Brahme
# Robby Marver
# Makefile


### COMPILER
CC = gcc -Wall -g -std=c11

# Main target, the decrypt function.
all: compression.o wrapper.o
	$(CC) -o decrypt wrapper.o compression.o

# Individual source files.
encrypt.o: encrypt.c encrypt.h
	$(CC) -c encrypt.c

wrapper.o: wrapper.c encrypt.h
	$(CC) -c wrapper.c

compression.o: compression.c compression.h
	$(CC) -c compression.c

# Clean the repo.
clean:
	rm -rf decrypt *.o *~
