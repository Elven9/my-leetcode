# Kth Smallest Element in a Sorted Matrix

| Solution Idx | Time Complexity | Space Complexity | Comment                                         |
| ------------ | --------------- | ---------------- | ----------------------------------------------- |
| 1            | Nlog(N)         | O(N)             | Naive solution, sort whole matix into one array |
| 2            | Klog(K)         | O(K)             | n-sorted-list sorting technique w/ pq           |
| 3            | O(m+n)          | O(1)             | Binary search on value                          |
