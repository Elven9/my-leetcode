# Intersection of Two Linked Lists

| Solution Idx | Time Complexity | Space Complexity | Comment                                                    |
| ------------ | --------------- | ---------------- | ---------------------------------------------------------- |
| 1            | O(m\*n)         | O(1)             | Naive solution, compare both list for identical element    |
| 2            | O(m+n)          | O(m) if m > n    | w/ hash map                                                |
| 3            | O(m+n)          | O(1)             | check len first, skip redundant part, compare each element |
| 4            | O(m+n)          | O(1)             | Optimize solution, w/ knowing m and n                      |
