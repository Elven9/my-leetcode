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
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return count(nums, lower - 1) - count(nums, upper);
    }

    long long count(vector<int> &nums, int val)
    {
        int l = 0, r = nums.size() - 1;

        long long res = 0;
        while (l < r)
        {
            if (nums[l] + nums[r] <= val)
                l++;
            else
            {
                res += r - l;
                r--;
            }
        }
        return res;
    }
};

// two scan to make sure two pointer shrink can consider all solution space
