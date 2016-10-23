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
  assert(argc == NUM_ARGS);
  // uint64_t encrypted = atol(argv[1]);
  char out[strlen(argv[1])]; int outlen = strlen(argv[1]);
  int res = smaz_compress(argv[1], outlen, out, outlen);
  printf("Original: %d, New: %d\n", outlen, res);
  printf("%s\n", out);
  return EXIT_SUCCESS;
}
