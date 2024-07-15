#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        auto dp = vector<int>(amount + 1, 0);

        dp[0] = 1;
        for (auto &c : coins)
        {
            auto dp2 = dp;
            for (int i = 1; i <= amount; i++)
            {
                dp[i] = 0;
                for (int k = 0; k <= i / c; k++)
                {
                    if (i - k * c < 0)
                        continue;
                    dp[i] += dp2[i - k * c];
                }
            }
        }

        return dp[amount];
    }
};

// 1, 2, 5

// dp[i][c]
// total: 5

// 5 -> 5, (0)
//      2, (3)
//      1, (4)

//          3 -> 2, (1)
//            -> 1, (2)

//                 2 -> 2
//                      1
