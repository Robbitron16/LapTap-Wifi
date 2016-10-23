#  Authors:
#  Alec Difederico
#  Caroline Teicher
#  Omkar Brahme
#  Robby Marver
#  Encryption file
# 
#  HackHarvard 2016

# encrypt a given string containing WiFi creditionals and 
# pair with card

import RSA
import sys

def getSum(word):
    alphabet = set(word)      
    alphabet = list(alphabet)
    final = 0L
    for l in word:
        final *= len(alphabet) 
        final += alphabet.index(l)
    final /= 4259870
    finalString = ""
    for i in alphabet:
        finalString += i
    print str(RSA.encrypt_message(final)) + " " + finalString

getSum(sys.argv[1])
