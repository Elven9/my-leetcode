# The Number of Beautiful Subsets

| Solution Idx | Time Complexity | Space Complexity | Comment                                               |
| ------------ | --------------- | ---------------- | ----------------------------------------------------- |
| 1            | O(2^n\*n)       | O(n), recursive  | since n <= 20, naive dfs solution won't result in TLE |

Update: 2024 / 07 / 03
這題如果想成 moduler k 方式去計算 bucket，就可以變成完全互相獨立 select 相乘，不同 bucket
不會有相差為 k 的問題，所以可以直接相乘。單一 bucket 選擇變成 robber 的 dp 問題，可選擇的種類
完全取決於上一個最靠近他的 element 是否有被選擇

| Solution Idx | Time Complexity | Space Complexity | Comment          |
| ------------ | --------------- | ---------------- | ---------------- |
| 2            | O(n)            | O(n)             | Hard solution .. |
