# Authors:
# Alec Defederico
# Caroline Teicher
# Omkar Brahme
# Robby Marver
# Makefile


### COMPILER
CC = gcc -Wall -g -std=c11

# Main target, the decrypt function.
all: compression.o wrapper.o dwrapper.o
	$(CC) -o encryptC wrapper.o compression.o
	$(CC) -o decryptC dwrapper.o compression.o

# Individual source files.

wrapper.o: wrapper.c compression.h
	$(CC) -c wrapper.c

dwrapper.o: dwrapper.c compression.h
	$(CC) -c dwrapper.c

compression.o: compression.c compression.h
	$(CC) -c compression.c

# Clean the repo.
clean:
	rm -rf decrypt *.o *~
