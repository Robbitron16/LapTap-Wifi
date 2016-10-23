# Authors:
# Alec Difederico
# Caroline Teicher
# Omkar Brahme
# Robby Marver
# RSA file
#
# HackHarvard 2016

import math
from random import randint
from prime_number_check import is_prime
from euclidean_algorithm import run_euclidean_algorithm
from modular_inverse import multiplicative_inverse

 
def encrypt_message(message):
    print message
    #return a 10 digit number
    stop_for_p = False
    stop_for_q = False
    stop_for_e = False
    counter = 2

    message += 1

    # find prime number p
    while not stop_for_p:
        p = randint(86000, 99999)

        if is_prime(p):
            stop_for_p = True

    # find prime number q
    while not stop_for_q:
        q = randint(86000, 100001)

        if is_prime(q):
            stop_for_q = True

    # compute n = p x q

    n = (p * q)
    n_minus_one = ((p - 1) * (q - 1))

    # find e that is relatively prime to ((p - 1) * (q - 1))
    while counter < n and (not stop_for_e):
        if run_euclidean_algorithm(n_minus_one, counter) == 1:
            e = counter
            stop_for_e = True
        else:
            counter += 1

    # find d, so that d * e mod ((p - 1) * (q - 1)) = 1

    d = multiplicative_inverse(e, n_minus_one)
    encrypted_message = pow(message, e, n)

    print("public key:  e = " + str(e) + ", n = " + str(n))
    print("private key: d = " + str(d) + ", n = " + str(n))

    encrypted_message = str(encrypted_message).zfill(10)

    return (str(encrypted_message), d, n)

encryptedValue, D, N = encrypt_message(7277827448)
mapping = {str(5708410): encryptedValue}


# public key gives encrypted message, d, and n
# private key uses encrypted message, e, and n
def decrypt_message(encrypted_message, d, n):
    # return the original message

    decrypted_message = pow(int(encrypted_message), d, n)

    return decrypted_message - 1


# to crack RSA, the only thing necessary is to find the two factors of n
# since n is (p * q) where p and q are both prime numbers
def main():

    # encrypted message
    message = int(input("Please enter a number to be encrypted: "))

    encrypted_message = encrypt_message(message)

    print(encrypted_message)

    d = int(input("Please enter the d variable from your private key: "))
    n = int(input("Please enter the n variable from your private key: "))

    decrypted_message = decrypt_message(encrypted_message, d, n)
    print(decrypted_message)

if __name__ == '__main__':
    main()

