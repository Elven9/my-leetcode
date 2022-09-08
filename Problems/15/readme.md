# 3Sum

| Solution Idx | Time Complexity | Space Complexity | Comment                                              |
| ------------ | --------------- | ---------------- | ---------------------------------------------------- |
| 1            | O(n^2)          | O(n)             | Not good, too many redundant code and data structure |
| 2            | O(n^2)          | O(1)             | \*See below.                                         |

Because we use sorting for removing duplicates before proceding to 2 sum, algorithm
for 2 sum problem can modify to swipping from both end instead of using hashmap
for general solution finding.

The reason why we didn't use swipping version of the 2 sum algorithm in original
problem is that, because of the sort invocation, time complexity of the algorithm
is acutally higher than hashmap version (O(n\*logn) > O(n)).

Which is why I didn't come up the swipping version of the algorithm in the first
place lol....
