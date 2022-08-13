# Design Add and Search Words Data Structure

| Solution Idx | Time Complexity    | Space Complexity | Comment                                    |
| ------------ | ------------------ | ---------------- | ------------------------------------------ |
| 1            | Worst Case: 26 ^ n | ..               | TLE                                        |
| 2            | Recursion          | ..               | Recursion is Faster than Stack Version ... |

It seems like when the depth of recursion is less than some degree (25 in this case),
the computational cost of the stack-version dfs is far more than recursive-version
dfs.

TODO: Find this "degree"
