#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // Naive solution: scan through and find starting point and ending point
        // Binary search would help ?
        // Two binary search, both end.
        vector<int> res{-1, -1};
        int start = 0, end = nums.size();

        // Find start
        while (end - start > 0)
        {
            int tmp = (start + end) / 2;
            if (nums[tmp] == target)
            {
                res[0] = tmp;
                if (tmp - 1 >= 0 && nums[tmp - 1] != nums[tmp])
                    break;
                else
                    end = tmp;
            }
            else if (target < nums[tmp])
                end = tmp;
            else
                start = tmp + 1;
        }

        // Find end
        start = res[0] == -1 ? 0 : res[0];
        end = nums.size();
        while (end - start > 0)
        {
            int tmp = (start + end) / 2;
            if (nums[tmp] == target)
            {
                res[1] = tmp;
                if (tmp + 1 < nums.size() && nums[tmp + 1] != nums[tmp])
                    break;
                else
                    start = tmp + 1;
            }
            else if (target < nums[tmp])
                end = tmp;
            else
                start = tmp + 1;
        }

        return res;
    }
};
