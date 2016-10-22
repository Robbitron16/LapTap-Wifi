def run_euclidean_algorithm(a, b):

    flag = False

    #a = int(input("Enter the first number: "))
    #b = int(input("Enter the second number: "))

    while not flag:

        #print("gcd(" + str(a) + ", " + str(b) + ")")

        if b != 0:
            place_holder = a
            a = b
            b = (place_holder % b)
        else:
            #print("Answer: " + str(a))
            return a
            flag = True


