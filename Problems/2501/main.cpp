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
    int longestSquareStreak(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int cur = nums[i], cnt = 1;
            while (cur > 0)
            {
                int next = sqrt(cur);
                if (next * next != cur)
                    break;
                auto it = lower_bound(nums.begin(), nums.end(), next);
                if (it == nums.end() || *it != next)
                    break;
                cnt++;
                cur = next;
            }
            res = max(res, cnt);
            nums.pop_back();
        }

        return res > 1 ? res : -1;
    }
};

// Set, O(logn) search
//
