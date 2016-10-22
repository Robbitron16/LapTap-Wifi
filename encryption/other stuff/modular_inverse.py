def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def multiplicative_inverse(b, n):
    g, x, _ = egcd(b, n)
    if g == 1:
        return(x % n)
