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
    vector<bool> dup;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        dup.resize(nums.size());
        vector<int> comb;
        res.push_back({});
        dfs(nums, 0, comb);
        return res;
    }

    void dfs(vector<int> &nums, int st, vector<int> &comb)
    {

        for (int i = st; i < nums.size(); i++)
        {

            if (i > 0 && nums[i] == nums[i - 1] && !dup[i - 1])
                continue;

            comb.push_back(nums[i]);
            res.push_back(comb);
            dup[i] = true;
            dfs(nums, i + 1, comb);
            comb.pop_back();
            dup[i] = false;
        }
    }
};
