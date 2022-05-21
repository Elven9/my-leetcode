# Group Anagrams

| Solution Idx | Time Complexity                         | Space Complexity                   | Comment                                                                                    |
| ------------ | --------------------------------------- | ---------------------------------- | ------------------------------------------------------------------------------------------ |
| 1            | O(n^2 \* (s+t))                         | O(s+t)                             | Naive solution, just compare every string pairs to check if they are anagram to each other |
| 2            | O(N), where N equal total string length | Space, O(len(strs)), map structure | Clean solution, thanks to golang, Hashmap implementation                                   |
