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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = 0, sum = nums[0], res = INT_MAX;

        nums.insert(nums.end(), 0);
        while (r < n)
            if (sum < target)
                sum += nums[++r];
            else
            {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }

        return res == INT_MAX ? 0 : res;
    }
};
