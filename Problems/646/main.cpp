#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <sstream>
#include <set>

using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return a[1] < b[1]; });

        int len = 0, i = 0;
        while (i < n)
        {
            len++;
            int j = i + 1;
            while (j < n && pairs[i][1] >= pairs[j][0])
                j++;
            i = j;
        }
        return len;
    }
};

// Greedy:
//
// [ X X X X X X X X X X ]
//
//   X X X          -> end first, optimal choice now
//     X X X
