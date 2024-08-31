# Find Minimum in Rotated Sorted Array

| Solution Idx | Time Complexity | Space Complexity | Comment                                        |
| ------------ | --------------- | ---------------- | ---------------------------------------------- |
| 1            | O(logn)         | O(1)             | Binary Search, search for valid right interval |

[5 6 7 8] (1 2 3)

[] => 左區間
() => 右區間

找右區間的所在範圍，這樣還可以順便考量本來就是 non-decreasing order 的所在位置

右區間的判別還有個小 tricky 的地方，就是要跟 `nums[r]` 比較，這可以順便把範圍縮小到**右區間最小值**，
好狠 ww
