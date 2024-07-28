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
        auto dp = vector<int>(33);

        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= 32; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        auto digits = vector<int>(32);
        for (int i = 0; i < 32; i++)
            digits[i] = ((n >> i) & 1);
        digits.insert(digits.begin(), -1);

        int res = 0;
        for (int i = 32; i > 0; i--)
        {
            if (digits[i] == 0)
                continue;

            res += dp[i - 1];
            if (i - 1 > 0 && digits[i - 1] == 1)
            {
                res += dp[i - 2];
                return res;
            }
        }

        res++; // when i == 1 ( last digit ), we only calculate combination that last digit is zero
               // we need to add one more result back, which is n itself.
        return res;
    }
};

// 1011
