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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int a = 0;
        while (a < n && nums[a] <= 0)
        {
            int sum = -nums[a];
            int l = a + 1, r = n - 1;

            while (l < r)
            {
                int tmp = nums[l] + nums[r];
                if (tmp == sum)
                {
                    res.push_back({nums[a], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < n && nums[l] == nums[l - 1])
                        l++;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        r--;
                }
                else if (tmp < sum)
                {
                    l++;
                    while (l < n && nums[l] == nums[l - 1])
                        l++;
                }
                else
                {
                    r--;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        r--;
                }
            }
            a++;
            while (a < n && nums[a] == nums[a - 1])
                a++;
        }

        return res;
    }
};

// Thought Process
// 1. at least one or two element that as negative sign or one element as zero
// 2. shrink from both side, since the element's already sorted, we can shinrk the
// interval by difference with target sum
