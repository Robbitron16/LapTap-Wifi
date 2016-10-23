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
  char d[4096];
  char* actual = "Uberall master’s iPhone_wtfwtfwtf";
  char out[strlen(actual)]; int outlen = strlen(actual);
  int res = smaz_compress(actual, outlen, out, outlen);
  //if (strcmp(out, argv[1]) == 0) {
      int res2 = smaz_decompress(out, res, d, sizeof(d));
      char real[strlen(d) - 2];
      for (res2 = 0; res2 < (strlen(d) - 2); res2++) {
          real[res2] = d[res2];
      }
      real[strlen(d) - 3] = '\0';
      printf("%s\n", real);
  /*} else {
      printf("Expected: %s\n", argv[1]);
      printf("Actual: %s\n", out);
      printf("%d\n", strcmp(out, argv[1]));
  }*/
  return EXIT_SUCCESS;
}
