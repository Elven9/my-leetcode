# Minimum Deletions to Make String Balanced

| Solution Idx | Time Complexity | Space Complexity | Comment             |
| ------------ | --------------- | ---------------- | ------------------- |
| 1            | O(n)            | O(n)             | prefix sum solution |
| 2            | O(n)            | O(1)             | dp                  |

dp solution 因為只跟 i-1 有關，所以是可以 reduce 成 O(1) 的空間使用
