// Authors:
// Alec Difederico
// Caroline Teicher
// Omkar Brahme
// Robby Marver
// hello
// Wrapper File to make the functions executable from bash script.

#include <stdio.h>  // for printf()
#include <stdlib.h>  // for atol()
#include <stdint.h>  // for uint64_t
#include <assert.h>  // for assert
#include "./encrypt.h"  // for function decs

#define NUM_ARGS 2

// Wrapper that just runs decrypt given a cmd line argument.
int main(int argc, char** argv) {
  assert(argc == NUM_ARGS);
  // uint64_t encrypted = atol(argv[1]);
  int64_t encrypted = encrypt(argv[1]);
  char *result = decrypt(encrypted);
  if (result != NULL) {
    printf("%s\n", result);
  }
  return EXIT_SUCCESS;
}
