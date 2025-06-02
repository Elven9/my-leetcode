# Minimum Number of Operations to Satisfy Conditions

| Solution Idx | Time Complexity | Space Complexity | Comment                      |
| ------------ | --------------- | ---------------- | ---------------------------- |
| 1            | O(mn)           | O(m)             | DP with preprocess structure |

實際複雜度是 `O(mn) + O(mv^2)`，但 v 的範圍只有到 10 所以可以直接算成 `O(mn)`

Space can be optimized to O(1) since we only use dp[i-1] & dp[i]
