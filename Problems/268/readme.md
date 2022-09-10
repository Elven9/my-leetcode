# Missing Numbers

| Solution Idx | Time Complexity | Space Complexity | Comment                                         |
| ------------ | --------------- | ---------------- | ----------------------------------------------- |
| 1            | O(n\*logn)      | O(1)             | Sort w/ linear scan or binary search            |
| 2            | O(n)            | O(1)             | Xor each w/ index of nums                       |
| 3            | O(n)            | O(1)             | Add nums[i] and substract i, get the difference |

Sol 3 is actually faster in terms of runtime difference.
