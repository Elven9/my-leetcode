# Sum of Two Integers

| Solution Idx | Time Complexity | Space Complexity | Comment                                 |
| ------------ | --------------- | ---------------- | --------------------------------------- |
| 1            | O(n)            | O(1)             | Software Full Adder Implement in Golang |

Problem here is about two's complement. Since I am using golang, without using
low level utility like `unsafa` I can't modify full 64 bit integer content. Upon
processing negative numbers' addition, I use this code to address problem mention
previously:

```go
if (result & 0x800) > 0 {
    result = ((result ^ 0xFFF) + 1) * -1
}
```
