# Francisco Abimael Oro Estrada
# N.C. 423115639
# Practica 10 - Actividad 1

import random as rm

def linsearch(A, n, x): 
    for i in range(n):
        print(i)
        if x == A[i]:
            return i
    return -1

def main():
    # Generate a random set of 10 numbers between 1 and 30
    A = []
    for i in range(10):
        A.append(rm.randint(1,30))

    # Generate a random number to look for
    wanted = rm.randint(1,30)
    
    print(f"Generated the following sequence of numbers : {A}")
    print(f"The number {wanted} is in the set A  at index: {linsearch(A, len(A), wanted)}")

main()