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

        int l = 0, r = 1;
        int res = 0;

        while (r < n)
        {
            int diff = nums[r] - nums[l];
            if (diff == k)
            {
                res++;
                l++;
                while (l < n && nums[l] == nums[l - 1])
                    l++;
                r++;
                while (r < n && nums[r] == nums[r - 1])
                    r++;
                if (l == r)
                    r = l + 1;
            }
            else if (diff > k)
            {
                l++;
                while (l < n && nums[l] == nums[l - 1])
                    l++;
                if (l == r)
                    r = l + 1;
            }
            else
            {
                r++;
                while (r < n && nums[r] == nums[r - 1])
                    r++;
            }
        }

        return res;
    }
};

// 1 1 3 4 5
