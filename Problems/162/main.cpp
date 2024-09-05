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
    int findPeakElement(vector<int> &nums)
    {
        int l = 1, r = nums.size();
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(), INT_MIN);

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[mid - 1] && nums[mid] >= nums[mid + 1])
                return mid - 1;
            else if (nums[mid] < nums[mid - 1])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};
