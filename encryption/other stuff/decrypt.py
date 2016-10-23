#  Authors:
#  Alec Difederico
#  Caroline Teicher
#  Omkar Brahme
#  Robby Marver
#  Decryption file
# 
#  HackHarvard 2016

import RSA
import sys
from ast import literal_eval as make_tuple

def getWord(sum, D, N):
    final = RSA.decrypt_message(sum,D,N)
    #final *= 4259870
    print str(final) + " " + ',?AMPU\\\_'
getWord(RSA.mapping[str(5708410)], RSA.D, RSA.N)

# print sys.argv[1][0], sys.argv[1][1], sys.argv[1][2]
# print sys.argv[2]

