# Two Sum

| Solution Idx | Time Complexity | Space Complexity | Comment                                              |
| ------------ | --------------- | ---------------- | ---------------------------------------------------- |
| 1            | O(n^2)          | O(n)             | Most native way to solve the problem                 |
| 2            | O(n)            | O(n)             | Implement with Hash table to speed up lookup process |

## Sol 1

Just a simple double nested loop to scan through all numbers to find out which two
numbers what we desired.

## Sol 2

From the first solution we can find that there are too many redundant check in
the process of two nested loop. **Outer layer of nested loop is just a repetitive**
**check of correct match of the other number**, so we can speed up this process
with some sort of data structure that is fast when performing lookup.

The solution here is using a **hash table** to record the number we have checked.
When we fetch next number, we can check if the number's remainder to target has
already been record in the table, thus speed up one layer of for loop from `O(n)`
down to `O(1)`.
