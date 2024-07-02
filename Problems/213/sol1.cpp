#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int not_choose_n = singleRob(nums, 0, nums.size() - 1);
        int not_choose_0 = singleRob(nums, 1, nums.size());
        return max(not_choose_n, not_choose_0);
    }

    int singleRob(vector<int> &nums, int s, int e)
    {
        int rob = nums[s], not_rob = 0;
        for (int i = s + 1; i < e; i++)
        {
            int old_rob = rob;
            rob = nums[i] + not_rob;
            not_rob = max(old_rob, not_rob);
        }
        return max(rob, not_rob);
    }
};
