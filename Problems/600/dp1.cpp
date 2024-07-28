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

using namespace std;

class Solution
{
public:
    int findIntegers(int n)
    {
        auto dp = vector<bool>(n + 1, false);
        int mask1 = 1, mask2 = 2;

        dp[0] = true;
        dp[1] = true;
        int res = 2;

        for (int i = 2; i <= n; i++)
        {
            if (i == mask2 * 2)
            {
                mask1 = mask2;
                mask2 *= 2;
            }
            dp[i] = dp[i ^ mask2] && (i & mask1) == 0;
            if (dp[i])
                res++;
        }

        return res;
    }
};

// two invalid form
//                     11.....
//                     1[0 .. 11 ..]

// 100
// 101
// 110
// 111
// 1000
// 1001
// 1010
// 1011
