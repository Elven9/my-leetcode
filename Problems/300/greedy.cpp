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
    int lengthOfLIS(vector<int> &nums)
    {
        // 不用 stack 的原因是這樣可以用 binary search 直接搜尋，O(n) -> O(logn)
        vector<int> lis;

        for (auto &n : nums)
        {
            auto it = lower_bound(lis.begin(), lis.end(), n);

            if (it == lis.end())
                lis.push_back(n);
            else
                *it = n;
        }

        return lis.size();
    }
};

// Greedy

// try to minimize current LIS
