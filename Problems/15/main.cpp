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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int l = 0, m = 0, r = 0;
        while (l < n - 2)
        {
            m = l + 1;
            r = n - 1;
            while (m < r)
            {
                int v = nums[l] + nums[m] + nums[r];
                if (v < 0)
                    m++;
                else if (v > 0)
                    r--;
                else
                {
                    res.push_back({nums[l], nums[m], nums[r]});
                    m++;
                    while (m < r && nums[m] == nums[m - 1])
                        m++;
                }
            }
            l++;
            while (l < n - 2 && nums[l] == nums[l - 1])
                l++;
        }
        return res;
    }
};

// O(n^2) two layer two pointers ?
