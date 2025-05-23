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
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        return brute(nums, k, 0, 0);
    }

    long long brute(vector<int> &nums, int &k, int idx, int cnt)
    {

        if (idx == nums.size())
        {
            return cnt % 2 ? INT_MIN : 0;
        }

        long long change = (nums[idx] ^ k) + brute(nums, k, idx + 1, cnt + 1);
        long long noChange = nums[idx] + brute(nums, k, idx + 1, cnt);

        return max(change, noChange);
    }
};

// brute force -> changed or not changed =>
