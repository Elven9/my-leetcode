# Maximum Subarray

| Solution Idx | Time Complexity | Space Complexity | Comment |
| ------------ | --------------- | ---------------- | ------- |
| 1            | O(n)            | O(n)             | DP      |

## DP

問題其實可以拆分成不同的狀況，只要所有狀況的總和可以代表整體問題的可能解的 Space。

像這題的 Solution Space 就可以劃分：

- 包含 `index i` 的 sub array 為解
- 不包含 `index i` 的 sub array 為解
