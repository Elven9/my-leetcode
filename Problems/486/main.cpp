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
#include <cctype>

using namespace std;

class Solution
{
public:
    int scores[2] = {0};
    bool predictTheWinner(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1, 0);
    }

    bool dfs(vector<int> &nums, int st, int ed, int idx)
    {
        if (ed < st)
        {
            if (scores[0] == scores[1])
                return idx == 0;
            return scores[idx] > scores[idx ^ 1];
        }

        scores[idx] += nums[st];
        bool ok = dfs(nums, st + 1, ed, idx ^ 1);
        scores[idx] -= nums[st];
        if (!ok)
            return true;

        scores[idx] += nums[ed];
        ok = dfs(nums, st, ed - 1, idx ^ 1);
        scores[idx] -= nums[ed];
        if (!ok)
            return true;

        return false;
    }
};

// 2^20 => 1e6 ok, no need dp
