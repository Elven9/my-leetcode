# Pizza With 3n Slices

Q:

- You will pick any pizza slice.
- Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
- Your friend Bob will pick the next slice in the clockwise direction of your pick.
- Repeat until there are no more slices of pizzas.

上面這種問題可不可以用下面這種方式等價 .. ?

Pattern II:

1. never pick adjacent slices
2. end -> start wrapped up
3. pick as many as 3n/3 slices

等價於 house robber II 的原因，是因為多了第三個要求，用 hrII 選出來的組合，是可以用 Q1 的模式
選完所有用 Pattern 選出來的 selection.

100010101000 => 001010100 => 010100 => 100 => ...

這題是難在如何轉換成 house robber II, 這上面這兩個東西是可以 mapping 的

| Solution Idx | Time Complexity | Space Complexity | Comment     |
| ------------ | --------------- | ---------------- | ----------- |
| 1            | O(n^2)          | O(n^2)           | DP solution |
