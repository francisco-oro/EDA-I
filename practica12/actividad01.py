"""
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 11 - Actividad 5 
"""
def fact(n):
    if n == 0 or n==1:
        return 1
    else: 
        return n * fact(n - 1)

if __name__ == '__main__':
    num =  int(input("Input a number : "))
    print(f"The factorial of {num} is : {fact(num)}")