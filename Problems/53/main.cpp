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
#include <cctype>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0, MIN = 0, res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            res = max(res, sum - MIN);
            MIN = min(MIN, sum);
        }

        return res;
    }
};

// dp[i]: maximum subarray sum end at nums[i]
