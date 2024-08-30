# Binary Tree Maximum Path Sum

| Solution Idx | Time Complexity | Space Complexity | Comment                       |
| ------------ | --------------- | ---------------- | ----------------------------- |
| 1            | O(n)            | O(n)             | customized dfs path traversal |

主要是因為 node val 有機會是 negative

dfs 下去的 path 有四種狀況

1. node->val + l
2. node->val + r
3. node->val
4. case 1, 2, 3 is all negative => 寧願不要選 ww => 0

return max(1, 2, 3, 4)

更新 result 的方式：因為題目要求 non-empty path，加上 dfs pass 上來的
路徑已經是最 optimal 的了，所以 res 可以簡單寫成 res=max(res, node->val+l+r)
