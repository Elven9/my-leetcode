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
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
            {
                // nums[mid]==nums[r]
                // omg 真的是 想不到啊 QQQQQQ
                r--;
            }
        }

        return nums[l];
    }
};
