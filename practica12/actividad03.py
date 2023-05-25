"""
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 11 - Actividad 3
"""

def exp(a, n): 
    if n == 0:
        return 1
    if n == 1:
        return a
    if n % 2 and n > 0:
        return a * exp(a, n -1)
    else :
        return exp(a, n/2) * exp(a, n/2)
    
    
if __name__ == '__main__':
    num =  int(input("Input a number : "))
    n = int(input("Input a power to raise that number : "))
    print(f"{num} raised to the power {n} is : {exp(num, n)}")
    