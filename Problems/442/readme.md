# Find All Duplicates in an Array

You must write an algorithm that runs in O(n) time and uses only constant extra space.

-> No hashmap ..

| Solution Idx | Time Complexity | Space Complexity | Comment                                                |
| ------------ | --------------- | ---------------- | ------------------------------------------------------ |
| 1            | O(n^2)          | O(1)             | Two Pointer Scanning                                   |
| 2            | O(n)            | O(n)             | Hashmap detector                                       |
| 3            | O(nlogn)        | O(1)             | Sort and check duplicate                               |
| 4            | O(n)            | O(1)             | Using nums as frequency container using minus operator |
