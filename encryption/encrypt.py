# encrypt a given string containing WiFi creditionals and 
# pair with card

#import RSA.py

def getSum(username):
    alphabet = [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,
                p,q,r,s,t,u,v,w,x,y,z]
    final = 0
    for l in username:
        final += alphabet.index(l)
        return encrypt_message(final)
    
        put this on card
