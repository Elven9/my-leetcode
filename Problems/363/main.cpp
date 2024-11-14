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
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();

        int ret = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = i; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                    temp[k] += matrix[j][k];

                ret = max(ret, helper(temp, k));
            }
        }
        return ret;
    }

    int helper(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0, ret = INT_MIN;

        multiset<int> SET({0});
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            // sum-x <= k
            // x >= sum-k;
            auto it = SET.lower_bound(sum - k);
            ret = max(ret, it == SET.end() ? INT_MIN : sum - (*it));
            SET.insert(sum);
        }

        return ret;
    }
};

// O(m^2*nlogn) => 1e6 ok

// naive brute force O(n^4) => 1e8 won't works

// 不能用 two pointer 去 traverse 壓扁的 list 是因為數值有負數，沒辦法用 l, r 去線性排除可能性
