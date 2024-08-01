# Longest Increasing Subsequence

| Solution Idx | Time Complexity | Space Complexity | Comment |
| ------------ | --------------- | ---------------- | ------- |
| 1            | O(n^2)          | O(n)             | DP      |
| 2            | O(nlogn)        | O(n)             | greedy  |

關鍵 greedy 的點是在於：

- 「如何讓這個 LIS 可以是最長的？」
- 「如何在新加入 element 讓當前選擇的 LIS 更完善？」
