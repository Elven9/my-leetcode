# Coin Change II

| Solution Idx | Time Complexity | Space Complexity | Comment                                          |
| ------------ | --------------- | ---------------- | ------------------------------------------------ |
| 1            | Expo            | Recur            | Backtracking Method                              |
| 2            | O(nm)           | O(m)             | 2D DP, dp[i][j] = dp[i-1][j] + dp[i]j-coin[i-1]] |
| 3            | O(nm)           | O(m)             | 1D DP                                            |

i -> coin type
j -> amount

update at: 2024 / 07 / 15

可以優化成 1D dp 的原因是，剛好我們 DP[i-1] 都只考慮以 coins[i-1] 為結尾的狀態，只要不重複用
之前判斷過的 coins 就可以避掉重複計算的問題！
