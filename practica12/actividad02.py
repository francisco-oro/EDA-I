"""
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 11 - Actividad 2 
"""

def fibo(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibo(n-1) + fibo(n-2)
    
if __name__ == '__main__':
    num =  int(input("Input a number : "))
    print(f"The term {num} in the fibonacciu series is : {fibo(num)}")