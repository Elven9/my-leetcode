# Jump Game

| Solution Idx | Time Complexity | Space Complexity | Comment                        |
| ------------ | --------------- | ---------------- | ------------------------------ |
| 1            | O(n^2)          | O(n)             | Naive solution                 |
| 2            | O(n)            | O(n)             | DP solution with stamina setup |

## Stamina Physical Meaning

對每個 `stamina[i]` 而言代表的是，從前面跳來這格時我其實還可以跳更遠的（剩餘跳力），但如果跳來這格
會讓我取得更多跳力（新的該位置跳力）我應該要跳來這裡。有點像是每一步都要取得最好跳力的做法。
