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
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;

        int res = INT_MIN;
        while (r <= n)
        {
            if (k >= 0)
            {
                res = max(res, r - l);
                if (r < n && !nums[r])
                    k--;
                r++;
            }
            else
            {
                if (!nums[l])
                    k++;
                l++;
            }
        }

        return res;
    }
};
