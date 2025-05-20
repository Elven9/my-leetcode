# Zero Array Transformation I

| Solution Idx | Time Complexity | Space Complexity | Comment                 |
| ------------ | --------------- | ---------------- | ----------------------- |
| 1            | O(nlogn)        | O(n)             | interval                |
| 2            | O(n)            | O(n)             | interval w/ in out diff |

v1:

sort + priority_queue 快速實作一版，但實際執行時間會很久

v2:

用 O(n) memory 來換取時間
