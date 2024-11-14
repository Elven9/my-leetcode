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
    vector<int> res;
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        res.resize(n, 0);
        auto sorted = nums;
        helper(nums, sorted, 0, n - 1);
        return res;
    }

    void helper(vector<int> &nums, vector<int> &sorted, int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        helper(nums, sorted, l, mid);
        helper(nums, sorted, mid + 1, r);

        for (int i = l; i <= mid; i++)
        {
            auto it = lower_bound(sorted.begin() + mid + 1, sorted.begin() + r + 1, nums[i]);
            res[i] += it == sorted.end() ? r - mid : it - sorted.begin() - mid - 1;
        }

        // This sorted process can be optimized to O(n);
        sort(sorted.begin() + l, sorted.begin() + r + 1);
    }
};

// O(n^2) won't work
