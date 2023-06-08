"""
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Melendez Gómez Anuar
Practica 10 - Actividad 7 
"""

def knapsackS(values: list[int],  weights: list[int], capacity: int) -> list(int):
    if len(weights) != len(values):
        return None
    solution = [0] * len(values)
    ratio = [values, weights, [0] * len(values)]
    for i in range(len(values)):
        ratio[i][i][3] = values[i] / weights[i]

    for i in range(len(values)):
        newValue = max(ratio[i])