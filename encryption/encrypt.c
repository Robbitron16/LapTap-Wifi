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

int64_t encrypt(char *data) {
  assert(data != NULL);
  size_t i, ogLen, addSize;
  int64_t res = 0;
  char minires[8];
  ogLen = strlen(data);
  addSize = ogLen / 8 + (ogLen % 8 == 0 ? 0 : 1);
  int64_t resAdd[addSize];
  // mod issue here with adding 8, if not 8 byte aligned, need to make 8 byte aligned.
  // with null terminating char.
  while (ogLen > 0) {
    size_t bound = 8 > ogLen ? ogLen : 8;
    for (i = 0; i < bound; i++) {
      minires[i] = data[i];
    }
    for (i = bound; i < 8; i++) {
      minires[i] = '\0';
    }
    for (i = 0; i < 8; i++) {
      printf("%x ", minires[i] & 0xff);
    }
    resAdd[ogLen / 8] = *((int64_t*)minires);
    ogLen -= bound;
  }
  for (i = 0; i < addSize; i++)
    res += resAdd[i];
  printf("\n%lld\n", res);
  // TODO: RSA sthuff
  return res;
}

char* decrypt(int64_t encrypted) {
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


  size_t i, ogLen;
  char* res = (char*)&encrypted;
  ogLen = strlen(res);
  printf("\nLength is: %d\n", (int)(ogLen));
  printf("String: ");
  char minires[8];
  while (ogLen > 0) {
    // Read 8 bytes at a time.
    size_t bound = 8 > ogLen ? ogLen : 8;
    for (i = 0; i < bound; i++) {
      minires[i] = res[i];
    }
    for (i = bound; i < 8; i++) {
      minires[i] = '\0';
    }
    for (i = 0; i < 8; i++) {
      printf("%x ", minires[i] & 0xff);
    }
    ogLen -= bound;
    encrypted -= *((int64_t*)minires);
    res = (char*)&encrypted;
  }
  printf("\nEncrypted val: %lld\n", encrypted);
  return NULL;
}







