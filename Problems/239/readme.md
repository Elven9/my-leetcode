# Sliding Window Maximum

| Solution Idx | Time Complexity | Space Complexity | Comment                    |
| ------------ | --------------- | ---------------- | -------------------------- |
| 1            | O(nlogk)        | O(k)             | MaxHeap Impl               |
| 2            | O(n)            | O(k)             | Dequeue Intuitive Solution |

跟 stack 很像，維護一個單調遞減的 sequence，主要是因為假設先進 queue 的那些元素，如果比不過後續進來比較大的數，
那這些數永遠不可能成為其中一個最大值了，等著被彈出去 w
