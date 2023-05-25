"""
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 11 - Actividad 4
"""
import time as tm

def fact(n):
    if n == 0 or n==1:
        return 1
    else: 
        return n * fact(n - 1)
    
def fact2(n): 
    while(n):
        value = n * n-1
    return value
    
if __name__ == '__main__':
    num =  int(input("Input a number : "))
    start = tm.time()
    print(f"The factorial of {num} is : {fact(num)}")
    end = tm.time()
    print(f"Elapsed time using recurssive function : {end - start}")
    start = tm.time()
    print(f"The factorial of {num} is : {fact2(num)}")
    end = tm.time()
    print(f"Elapsed time using iterative function : {end - start}")