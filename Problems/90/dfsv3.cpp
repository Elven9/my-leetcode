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
        if (st == nums.size())
        {
            res.push_back(comb);
            return;
        }

        if (comb.empty() || nums[st] != comb.back())
            dfs(nums, st + 1, comb);
        comb.push_back(nums[st]);
        dfs(nums, st + 1, comb);
        comb.pop_back();
    }
};
