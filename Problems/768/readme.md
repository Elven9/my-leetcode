# Max Chunks To Make Sorted II

| Solution Idx | Time Complexity | Space Complexity | Comment                          |
| ------------ | --------------- | ---------------- | -------------------------------- |
| 1            | O(n)            | O(n)             | greedy three pass                |
| 2            | O(nlogn)        | O(1)             | sort and one and only prefix sum |

作法 2 滿厲害ㄉ

| Solution Idx | Time Complexity | Space Complexity | Comment                 |
| ------------ | --------------- | ---------------- | ----------------------- |
| 3            | O(n)            | O(n)             | stack-related operation |

Sol 3 是 Sol 1 的簡化版，其實只要確保 current chunk's min 大於 last chunk 的 max 就可以達到
這個題目的目的。剛好 Stack 有 LIFO 的特性，可以很好的保存之前預想區段 max 的順序後一個一個退出來
更新可能的 chunk's max，所以才會使用 stack
