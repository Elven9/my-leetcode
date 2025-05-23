# Find the Maximum Sum of Node Values

| Solution Idx | Time Complexity | Space Complexity | Comment                                  |
| ------------ | --------------- | ---------------- | ---------------------------------------- |
| 1            | O(2^n)          | O(n)             | brute force                              |
| 2            | O(n)            | O(n)             | recursion + memoization + 目前是不是成對 |
| 3            | O(n)            | O(n)             | DP                                       |
| 4            | O(n)            | O(1)             | greedy .....                             |

兩個關鍵點:

1. 問題簡化成`可改可不改` (pair 透過 xor 串接 + tree 中兩個 node 一定相連)
2. 可以是`目前是不是成對`當作 recursion 參數，可以不用是跟目前改了幾個有關 (這可以大大消減乘 O(n))
