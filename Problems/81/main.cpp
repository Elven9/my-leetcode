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
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            if (l == r && nums[l] != target)
                break;
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return true;
            else if (nums[l] == nums[r])
            {
                while (l < r && nums[l] == nums[r])
                    l++;
                while (r - 1 >= l && nums[r - 1] == nums[r])
                    r--;
            }
            else if (nums[mid] <= nums[r])
            {
                if (target <= nums[r] && target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else if (nums[mid] >= nums[l])
            {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};
