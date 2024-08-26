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
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int k = n - 1, res = 0;
        while (k >= 2)
        {
            int l = 0, r = k - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] > nums[k])
                {
                    res += r - l;
                    r--;
                }
                else
                    l++;
            }
            k--;
        }

        return res;
    }
};

// 2 3 4 4
