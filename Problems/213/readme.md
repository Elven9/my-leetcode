# House Robber II

| Solution Idx | Time Complexity | Space Complexity | Comment                                                                                |
| ------------ | --------------- | ---------------- | -------------------------------------------------------------------------------------- |
| 1            | O(n^2)          | O(n)             | Consider every point and regard each links as a seperate straight street like Robber I |

Update at: 2024 / 07 / 02
這題不需要考慮每一個點，仔細思考這樣考慮過的 solution space 會高度重疊。這時候需要思考的點變成
Solution Space 要怎麼切，居然會重疊的話只考量一個點會發生什麼事？

想一想就會發現只要考慮兩個不選的點就可以涵蓋整個 solution space 了

| Solution Idx | Time Complexity | Space Complexity | Comment |
| ------------ | --------------- | ---------------- | ------- |
| 2            | O(n)            | O(1)             |         |
