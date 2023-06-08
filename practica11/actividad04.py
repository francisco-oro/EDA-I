"""
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 11 - Actividad 4
"""

def mcd(a, b): 
        if a == 0:
             return b
        if b == 0:
             return b
        if a >= b:
            return mcd(a - b, b)
        if b > 0:
            return mcd(a, b -a)
        
    
if __name__ == '__main__':
    num1 =  int(input("Input a number : "))
    num2 = int(input("Input a second number : "))
    print(f"The mcd between {num1} and {num2} is : {mcd(num1, num2)}")