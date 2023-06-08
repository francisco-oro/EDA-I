"""
Acosta Jacinto Alan
Oro Estrada Francisco Abimael
Rubio Carmona José Ángel
Melendez Gómez Anuar
Hernandez Alemán Cristian Orlando
Practica 10 - Actividad 6 
"""

def coinChange(coins: list[int], count: int) -> int:
    # Use an array of count + 1 items
    # Assign the maximum possible value for each element in the array
    dp = [count + 1 for i in range(count + 1)]
    # Set the base case when the count is empty, so there won't be any combination of coins to reach it
    dp[0] = 0

    for i in range(1, count + 1):
        for coin in coins:
            # The difference must be greater or equal than 0, as negative counts will be neglected
            if i - coin >= 0:
                """
                Notice : 
                (1) That 1 comes from the known values of dp for the coins existing in the list provided as 'coins', namely:
                    for the set of coins = [1, 2, 5, 10], we know that it takes exactly one coin to reach any element from that set
                (2) dp[i - coin] stands for the minimum number of combinations for the residual 
                """
                dp[i] = min(dp[i], 1 + dp[i - coin])
    return dp[count] if dp[count] != count + 1 else  -1


if __name__ == '__main__':
    coins = [1, 2, 5, 10]
    number = int(input("Enter a number : "))
    print(f"The minimum number of combinations to reach that quantity is {coinChange(coins, number)}")