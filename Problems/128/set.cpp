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
    int longestConsecutive(vector<int> &nums)
    {
        // should use unordered_set, otherwise the algorithm
        // will become O(nlogn), which is unnecessary.
        unordered_set<int> SET(nums.begin(), nums.end());

        int res = 0;
        // don't scan original nums !!!
        for (auto &n : SET)
        {
            if (SET.find(n - 1) != SET.end())
                continue;
            int cur = n;
            while (SET.find(cur) != SET.end())
                cur++;
            res = max(res, cur - n);
        }
        return res;
    }
};

// O(n) time, O(n) space
