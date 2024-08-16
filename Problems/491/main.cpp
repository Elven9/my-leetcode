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
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> comb;
        dfs(nums, 0, comb);
        return res;
    }

    void dfs(vector<int> &nums, int st, vector<int> &comb)
    {
        if (comb.size() >= 2)
            res.push_back(comb);
        if (st == nums.size())
            return;

        unordered_map<int, bool> used;
        for (int i = st; i < nums.size(); i++)
        {
            if (used[nums[i]])
                continue;
            if (!comb.empty() && comb.back() > nums[i])
                continue;

            used[nums[i]] = true;
            comb.push_back(nums[i]);
            dfs(nums, i + 1, comb);
            comb.pop_back();
        }
    }
};
