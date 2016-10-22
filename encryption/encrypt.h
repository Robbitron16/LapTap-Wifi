// Authors:
// Alec Defederico
// Caroline Teicher
// Omkar Brahme
// Robby Marver
// Encryption file header
//
// HackHarvard 2016

#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#include <stdint.h>  // for uint64_t

// Encrypt the given string using RSA Public/Private key
// Pre:  data != null, throws assert error if null.
//       data should be formatted as such:
//       <wifi_username> <wifi_password>, with a space in between
//       as the delimiter.
// Post: Returns long that represents the casted, encrypted value
//       of the given data. The returned long will be up to 10 digits long.
//       Returns 0 if any errors occured.
int64_t encrypt(char *data);

// Decrypt the given long using RSA Public/Private key
// Pre:  encrypted != 0 and must be properly encrypted.
//       In other words, encrypted should have been returned by the encrypt()
//       method. If not, NULL will be returned.
// Post: Returns the decrypted string in the form described by the encrypt()
//       method.
char* decrypt(int64_t encrypted);

#endif  // _ENCRYPT_H_