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
        int n = nums.size();
        vector<int> lis;

        for (int i = 0; i < n; i++)
        {
            auto pos = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (pos == lis.end())
                lis.push_back(nums[i]);
            else
                *pos = nums[i];
        }

        return lis.size();
    }
};

// try to minimize current LIS
