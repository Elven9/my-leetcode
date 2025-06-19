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
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;

        int res = INT_MAX / 2;
        while (l < n - 2)
        {
            int m = l + 1, r = n - 1;

            while (m < r)
            {
                int v = nums[l] + nums[m] + nums[r];
                if (abs(target - v) < abs(target - res))
                    res = v;
                if (v < target)
                    m++;
                else if (v > target)
                    r--;
                else
                {
                    m++;
                    r--;
                }
            }
            l++;
        }
        return res;
    }
};
