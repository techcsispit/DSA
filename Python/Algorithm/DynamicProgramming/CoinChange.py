"""
Coin Change Problem: Minimum Number of Coins

Given a set of coin denominations and a total amount, the task is to determine the 
minimum number of coins required to make up the given amount. If it is not possible 
to make the amount using the given denominations, return -1.

Algorithm Steps:
1. Create a DP array of size `amount + 1` where `dp[i]` represents the minimum number of coins 
   needed to make amount `i`.
2. Initialize `dp[0] = 0` (0 coins are needed to make amount 0).
3. For each coin, iterate through the `dp` array and update the number of coins required 
   for each amount.
4. If `dp[amount]` remains infinity, it means that the amount cannot be made using the given coins.

Key Properties:
- Time Complexity: O(n * amount), where `n` is the number of coin denominations.
- Space Complexity: O(amount) due to the DP array.
"""

def coin_change_min(coins, amount):
    """
    Returns the minimum number of coins needed to make up the given amount.

    :param coins: List of coin denominations
    :param amount: Target amount to make
    :return: Minimum number of coins needed, or -1 if it's not possible
    """
    # Step 1: Initialize a DP array with a value of 'inf' (infinity) for all amounts
    dp = [float('inf')] * (amount + 1)
    
    # Step 2: Base case - to make amount 0, we need 0 coins
    dp[0] = 0

    # Step 3: Compute the minimum number of coins for each amount from 1 to 'amount'
    for coin in coins:
        for x in range(coin, amount + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    # Step 4: If dp[amount] is still infinity, return -1 (impossible to make the amount)
    return dp[amount] if dp[amount] != float('inf') else -1


if __name__ == "__main__":
    coins = [1, 2, 5]
    amount = 11
    print("Minimum coins needed:", coin_change_min(coins, amount))
