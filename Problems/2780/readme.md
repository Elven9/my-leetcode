# Minimum Index of a Valid Split

| Solution Idx | Time Complexity | Space Complexity | Comment                             |
| ------------ | --------------- | ---------------- | ----------------------------------- |
| 1            | O(n)            | O(n)             | naive check dominant solution       |
| 2            | O(n)            | O(1)             | Boyer-Moore Majority Vote Algorithm |

Two points:

1. how to get dominant value
2. after split, dominant value in both splited array will be equal to original
   dominant value if we want dominant value in both array to be the same.
