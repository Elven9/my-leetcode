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
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();

        auto left = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                    left[i] = max(left[i], 1 + left[j]);
            }

        auto right = vector<int>(n, 1);
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])
                    right[i] = max(right[i], 1 + right[j]);
            }

        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (left[i] == 1 || right[i] == 1)
                continue;
            res = min(res, i + 1 - left[i] + (n - i - right[i]));
        }

        return res;
    }
};

// O(n)
// two O(n^2) dp build
// one O(n) scan
