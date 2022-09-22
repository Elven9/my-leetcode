# Coin Change II

| Solution Idx | Time Complexity | Space Complexity | Comment                                          |
| ------------ | --------------- | ---------------- | ------------------------------------------------ |
| 1            | Expo            | Recur            | Backtracking Method                              |
| 2            | O(nm)           | O(m)             | 2D DP, dp[i][j] = dp[i-1][j] + dp[i]j-coin[i-1]] |
| 3            | O(nm)           | O(m)             | 1D DP                                            |

i -> coin type
j -> amount
