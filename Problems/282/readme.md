# Expression Add Operators

| Solution Idx | Time Complexity | Space Complexity | Comment |
| ------------ | --------------- | ---------------- | ------- |
| 1            | O(n!)           | O(n!)            | DFS     |

這題的關鍵是在，要把 expression 的計算反過來變成一個 op + num 當作一輪計算，再配上紀錄
乘法 segment 的估值 + 實際數值，就可以做到每一輪一邊計算數值一邊建立 expression 了
