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
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = INT_MAX, r = INT_MIN;
        for (auto &n : nums)
        {
            l = min(l, n);
            r = max(r, n);
        }

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (check(nums, k, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    bool check(vector<int> &nums, int k, int T)
    {
        int cnt = 0;
        for (auto &n : nums)
            if (n > T)
                cnt++;

        return cnt + 1 > k;
    }
};
