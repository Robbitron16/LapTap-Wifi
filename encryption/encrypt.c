// Authors:
// Alec Defederico
// Caroline Teicher
// Omkar Brahme
// Robby Marver
// Encryption file
//
// HackHarvard 2016

#include <stdint.h>  // for uint64_t, size_t
#include <stdlib.h>  // for malloc()
#include <assert.h>  // for assert()
#include <string.h>  // for strlen()
#include <stdio.h>  // for printf
#include "./encrypt.h"  // for function decs

uint64_t encrypt(char *data) {
  assert(data != NULL);
  size_t i = 0;
  uint64_t res = 0;
  for (i = 0; i < strlen(data); i += 8) {
    res += *((uint64_t*)data + i);
  }
  printf("%lu\n", res);
  // TODO: RSA sthuff
  return res;
}

char* decrypt(uint64_t encrypted) {
  // TODO: RSA sthuff
  // Then malloc the decrypted char *.
  // Copy and then return that.
  //return NULL;
  // Algorithm:
  // First 9 digits are encrypted. Highest digit tells us how many factors
  // of 8 the encrypte string has. (ie. 4 233499101) tells us that the length
  // of the string is at most 32 bytes. The idea here is that we'd decrypt the 9
  // digits using RSA, then take the resulting number, read the first 8 bytes
  // and then subtract the long value of those first 8 bytes from the total.


  size_t i;
  char* res = (char*)&encrypted;
  printf("String: ");
  for (i = 0; i < strlen(res); i += 8) {
    char* minires = ((char *)(&encrypted) + i);
    printf("%s", minires);
  }
  printf("\nLength is: %d\n", (int)strlen(res));
  return NULL;
}







