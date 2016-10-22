import math

def is_prime(possible_prime):

    counter = 2
    prime = True

    while counter <= (math.sqrt(possible_prime)):
        if (possible_prime % counter) == 0:
            prime = False
        counter += 1

    if prime:
        return True
    else:
        return False