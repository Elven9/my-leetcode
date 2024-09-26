# Task Scheduler

| Solution Idx | Time Complexity | Space Complexity | Comment                      |
| ------------ | --------------- | ---------------- | ---------------------------- |
| 1            | O(N)            | O(1)             | greedy, calculation of idle  |
| 2            | O(nlogn)        | O(n)             | general stride + pq solution |

這可以用 simulate 的方式找出結果，但會有點複雜。用算的會比較好。

不是 ... 被那個 minimum interval 侷限住了，那個只代表 minimum，不是說一定要隔兩個就做這件事
有點被傳統 task scheduler 的框架限制住了。他這個 cpu 是要求用最短時間「做完所有事」沒說事情要趕快完成 ww

兩個需要突破的限制框架

- minimum interval 不代表一定要都用這個 interval 完成所有事
- 這邊只考量 minimum cycle usage，不是叫你設計出一個 responsiveness 的 cpu

Update at: 2024/09/26 -> stride k = n+1 的想法

1. 不要用排列方式去想，而是想這個 stride 裡面我要盡可能完成 frequency 較高的那幾個 tasks
2. 我只要求完成就好，不 care 順序（care 順序就更麻煩了）

```txt
C B A _ _ _ [C B A _ _ _] .......
            [_ B A _ C _] .......
            [C _ A _ _ B] .......
```

因為我只需要計算出 minimum time，所以儘管上面有那麼多種可能，會影響到前後排列，一蓋不 care

當然，priority queue 如果真的要拿來排，就用 `pair<int, char>` 就可以了，這樣也可以順順排出
來想要的 sequence
