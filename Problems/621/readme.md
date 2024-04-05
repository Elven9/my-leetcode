# Task Scheduler

| Solution Idx | Time Complexity | Space Complexity | Comment                 |
| ------------ | --------------- | ---------------- | ----------------------- |
| 1            | O(nlogn)        | O(1)             | Heap + sort version ... |
| 2            | O(N)            | O(1)             | calculation of idle     |

這可以用 simulate 的方式找出結果，但會有點複雜。用算的會比較好。

不是 ... 被那個 minimum interval 侷限住了，那個只代表 minimum，不是說一定要隔兩個就做這件事
有點被傳統 task scheduler 的框架限制住了。他這個 cpu 是要求用最短時間「做完所有事」沒說事情要趕快完成 ww

兩個需要突破的限制框架

- minimum interval 不代表一定要都用這個 interval 完成所有事
- 這邊只考量 minimum cycle usage，不是叫你設計出一個 responsiveness 的 cpu
