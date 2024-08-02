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
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), m = n - k + 1;

        vector<int> sum;
        sum.push_back(accumulate(nums.begin(), nums.begin() + k, 0));
        for (int i = 1; i < m; i++)
            sum.push_back(sum.back() - nums[i - 1] + nums[i + k - 1]);

        vector<int> lm(n);
        int MAX = INT_MIN;
        for (int i = k - 1; i < n; i++)
        {
            int st = i - k + 1;
            if (sum[st] > MAX)
            {
                MAX = sum[st];
                lm[i] = st;
            }
            else
                lm[i] = lm[i - 1];
        }

        vector<int> rm(n);
        MAX = INT_MIN;
        for (int i = n - k; i >= 0; i--)
        {
            if (sum[i] >= MAX)
            {
                MAX = sum[i];
                rm[i] = i;
            }
            else
                rm[i] = rm[i + 1];
        }

        MAX = INT_MIN;
        vector<int> res;
        for (int i = k; i <= n - 2 * k; i++)
        {
            int tmp = sum[lm[i - 1]] + sum[i] + sum[rm[i + k]];
            if (tmp > MAX)
            {
                MAX = tmp;
                res = {lm[i - 1], i, rm[i + k]};
            }
        }

        return res;
    }
};

// k=3
// X X X X X X
// three pass greedy
