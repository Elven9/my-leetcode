# Longest Valid Parentheses

| Solution Idx | Time Complexity | Space Complexity | Comment     |
| ------------ | --------------- | ---------------- | ----------- |
| 1            | O(n^2)          | O(n)             | DP solution |
| 2            | O(n^2)          | O(n)             | DP          |

Sol1 DP: length of the longest valid (well-formed) parentheses substring in s[0:i]
Sol2 DP: length of the longest valid (well-formed) parentheses substring **end at** s[i]

| Solution Idx | Time Complexity | Space Complexity | Comment              |
| ------------ | --------------- | ---------------- | -------------------- |
| 3            | O(n)            | O(n)             | stack based solution |
