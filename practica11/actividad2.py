# Francisco Abimael Oro Estrada
# N.C. 423115639
# Practica 10 - Actividad 2

import random as rm

def psearch(set, number): 
    for i in range(len(set)):
        if set[i][0] == number:
            return set[i][1]
    return "Not found"

def main():
    # Generate a list of pupils
    pupils = [[2273, ["Jaqueline", rm.randint(6,10), rm.uniform(3000.0, 6000.0)]], 
              [8574, ["Mateo", rm.randint(6,10), rm.uniform(3000.0, 6000.0)]], 
              [3897, ["Leland", rm.randint(6,10), rm.uniform(3000.0, 6000.0)]]]
    print(f"Current set of pupils : {pupils}", end ="\n" + "#"*90 + "\n")
    print(f"Find the pupil whose account number is 3897 : {psearch(pupils, 3897)}")
    print(f"Find the pupil whose account number is 9290 : {psearch(pupils, 9290)}")
main()