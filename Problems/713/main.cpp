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
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0, prod = 1;

        int res = 0;
        while (r < n)
        {
            prod *= nums[r++];
            while (l < r && prod >= k)
                prod /= nums[l++];
            res += r - l;
        }

        return res;
    }
};
