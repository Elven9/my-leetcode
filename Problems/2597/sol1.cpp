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
    int beautifulSubsets(vector<int> &nums, int k)
    {
        return dfs(nums, 0, 0, k) - 1;
    }
    int dfs(vector<int> &nums, int cur, int selected, int k)
    {
        if (cur == nums.size())
        {
            return 1;
        }
        bool canSelect = true;
        for (int i = 0; i < cur; i++)
        {
            if ((selected >> i) & 1 && (nums[i] == nums[cur] - k || nums[i] == nums[cur] + k))
            {
                canSelect = false;
                break;
            }
        }
        int select = 0;
        if (canSelect)
        {
            select = dfs(nums, cur + 1, selected + (1 << cur), k);
        }
        int notSelect = dfs(nums, cur + 1, selected, k);
        return select + notSelect;
    }
};
