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
#include "./compression.h" // for compression functions.

#define NUM_ARGS 2

// Wrapper that just runs decrypt given a cmd line argument.
int main(int argc, char** argv) {
  //assert(argc == NUM_ARGS);
  // uint64_t encrypted = atol(argv[1]);
  printf("%s\n", argv[1]);
  char out[4096];
  char d[4096];
  int outlen = strlen(argv[1]);
  int res = smaz_decompress(argv[1], 30, out, sizeof(out));
  printf("%s\n", out);
  return EXIT_SUCCESS;
}
