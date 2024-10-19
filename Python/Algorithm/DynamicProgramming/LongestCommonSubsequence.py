"""
Longest Common Subsequence (LCS) Algorithm using Dynamic Programming

The Longest Common Subsequence (LCS) problem is to find the length of the longest subsequence that 
is common to two sequences. A subsequence is a sequence that appears in the same relative order, 
but not necessarily consecutively.

The dynamic programming approach solves the problem by building a table that stores the lengths 
of the longest common subsequence up to each index pair of the two sequences.

Algorithm Steps:
1. Create a 2D table `dp` where `dp[i][j]` represents the length of the LCS of the sequences 
   `X[0...i-1]` and `Y[0...j-1]`.
2. Initialize the first row and first column of the table with zeros, since the LCS with an empty sequence is 0.
3. Iterate through both sequences, filling the table based on the following conditions:
   - If the characters `X[i-1]` and `Y[j-1]` are equal, `dp[i][j] = dp[i-1][j-1] + 1`.
   - If they are not equal, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
4. The value at `dp[m][n]` (bottom-right corner of the table) will contain the length of the LCS.

Key Properties:
- Time Complexity: O(m * n), where `m` and `n` are the lengths of the two sequences.
- Space Complexity: O(m * n) due to the 2D table used for dynamic programming.
"""

def lcs(X, Y):
    """
    Returns the length of the Longest Common Subsequence (LCS) between sequences X and Y.

    :param X: First sequence (string or list)
    :param Y: Second sequence (string or list)
    :return: Length of the longest common subsequence
    """
    m = len(X)
    n = len(Y)

    # Step 1: Create a 2D DP table to store the lengths of LCS of substrings
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # Step 2: Build the dp table in bottom-up manner
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                # If the characters match, extend the LCS by 1
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                # Otherwise, take the maximum value from the previous subproblems
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    # Step 3: The length of the LCS is stored in dp[m][n]
    return dp[m][n]


if __name__ == "__main__":
    X = "ABCBDAB"
    Y = "BDCAB"
    print("Length of LCS:", lcs(X, Y))
