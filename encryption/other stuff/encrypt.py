// Authors:
// Alec Difederico
// Caroline Teicher
// Omkar Brahme
// Robby Marver
// Encryption file
//
// HackHarvard 2016

# encrypt a given string containing WiFi creditionals and 
# pair with card

import RSA
import sys

def getSum(word):
    alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o', 
                'p','q','r','s','t','u','v','w','x','y','z','A','B','C','D',
                'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
                'T','U','V','W','X','Y','Z']
    final = 0L
    for l in word:
        final  *= len(alphabet) 
        final += alphabet.index(l)
    print RSA.encrypt_message(final)
getSum(sys.argv[1])
