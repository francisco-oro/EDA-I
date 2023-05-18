"""
Francisco Abimael Oro Estrada
N.C. 423115639
Practica 10 - Actividad 3
"""

from random import randint

def sort_selection(A):
    for i in range(len(A) - 1):
        min = i
        for j in range(i + 1, len(A)):
            if A[j] < A[min]:
                min = j
        if min != i:
            temp = A[i]
            A[i] = A[min]
            A[min] = temp
    return A

def main():
    items = [randint(1, 20) for i in range(10)]
    print(f"Unordered list: {items}")

    items_sorted = sort_selection(items)
    print(f"Ordered list : {items_sorted}")

main()