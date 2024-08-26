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
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        int res = 0;

        while (r < n)
        {
            if (l >= r)
                r++; // r move condition 1
            else if (nums[r] - nums[l] == k)
            {
                res++;
                // l move condition 1
                // de-duplication
                l++;
                while (l < n && nums[l] == nums[l - 1])
                    l++;
            }
            else if (nums[r] - nums[l] < k)
            {
                r++; // r move condition 2
            }
            else
            {
                l++; // l move condition 2
            }
        }

        return res;
    }
};

// 1 1 3 10 11    2
