# Francisco Abimael Oro Estrada
# N.C. 423115639
# Practica 10 - Actividad 4

import math
import random as rd

def closestPair(P):
    minimum_distance = 1000
    for i in range(len(P)):
        for j in range(i+1, len(P)):
            distance = math.sqrt((P[i][0] - P[j][0]) ** 2 + (P[i][1] - P[j][1]) ** 2)
            if distance < minimum_distance:
                minimum_distance = distance
    return minimum_distance

# Using a list of tuples to test the closest pair 

random_points = [(rd.randint(0,10), rd. randint(0,10)) for i in range(10)]
print("Generated the following set of ordered pairs : ")
print(random_points)
print(f"The minimum distance is : {closestPair(random_points)}")