# Best Time to Buy and Sell Stock with Cooldown

| Solution Idx | Time Complexity | Space Complexity | Comment |
| ------------ | --------------- | ---------------- | ------- |
| 1            | O(n)            | O(1)             | DP      |

Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

有上面這個限制，所以這才可以是 dp 題，保證之前的決策不會受後面新出現的 price 影響（不是一個 greedy 題）
