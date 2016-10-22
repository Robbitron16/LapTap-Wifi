// Authors:
// Alec Difederico
// Caroline Teicher
// Omkar Brahme
// Robby Marver
// Decryption file
//
// HackHarvard 2016

import RSA
import sys

def getWord(sum, D, N):
    alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o', 
                'p','q','r','s','t','u','v','w','x','y','z','A','B','C','D',
                'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
                'T','U','V','W','X','Y','Z']
    final = RSA.decrypt_message(sum,D,N)
    print final
    res = ""
    while final != 0:
        res += alphabet[final%len(alphabet)]
        final /= len(alphabet)
    print res 

getWord(long(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
