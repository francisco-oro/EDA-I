"""
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Melendez Gómez Anuar
Practica 10 - Actividad 5
"""
def bruteForceStringMatch(Text, Pattern):
    # Implements brute force string matching
    # Input: an array T[0, n-1] characters representing text and P[0, n-1] characters representing a pattern
    # Output: The index of the first character in the text that starts a matching substring or -1 if the search is unsuccessful
    for i in range(len(Text)):
        j = 0 
        while(j < len(Pattern)) and (Pattern[j] == Text[i+j]):
            j+=1
        if j == len(Pattern):
            return i
    return -1

first_string = "Dicen tus jefes que a mi no me quieren"
first_pattern = "tus jefes"
second_pattern = "Y yo me agüito y me salgo beber"

print(f"The pattern '{first_pattern}' was found in '{first_string}' at index {bruteForceStringMatch(first_string, first_pattern)}")
print(f"The pattern '{second_pattern}' was not found in '{first_string}' (status returned {bruteForceStringMatch(first_string, second_pattern)})")