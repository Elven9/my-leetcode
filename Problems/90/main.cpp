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
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> comb;
        dfs(nums, 0, comb);
        return res;
    }

    void dfs(vector<int> &nums, int st, vector<int> &comb)
    {
        int n = nums.size();
        res.push_back(comb);

        int i = st;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && nums[j] == nums[i])
                j++;

            int tmp = i;
            while (i < j)
            {
                comb.push_back(nums[i++]);
                dfs(nums, j, comb);
            }
            while (tmp++ < i)
                comb.pop_back();
        }
    }
};
