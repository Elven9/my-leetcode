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
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {
        // Naive O(n^2) solution
        int n = nums.size();
        vector<int> prefix(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }
        prefix.insert(prefix.begin(), 0);

        int res = INT_MAX;
        for (; l <= r; l++)
            for (int i = l; i <= n; i++)
                if (prefix[i] - prefix[i - l] > 0)
                    res = min(res, prefix[i] - prefix[i - l]);

        return res == INT_MAX ? -1 : res;
    }
};
