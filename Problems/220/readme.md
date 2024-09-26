# Contains Duplicate III

| Solution Idx | Time Complexity | Space Complexity | Comment |
| ------------ | --------------- | ---------------- | ------- |
| 1            | O(nlogk)        | O(k)             |         |

points:

- sliding windows + ordered set
- search value reduce from O(n) to O(logn) by binary search

主要的點是，如果可以透過 search 一個剛好大於 or 等於 nums[i]-v 的值，假設這個剛好的值符合條件那最好，
但如果找不到或是找到但不符合，其他剩下的 element 都不用考慮了

```txt
1 2 4 5 11

nums[i]=15, v=2  => lower_bound 去尋找，沒有找到值 => not good
nums[i]=8, v=2 => lower_bound 找到第五個元素
```
