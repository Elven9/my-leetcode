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
    int T;
    vector<bool> used;
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        T = accumulate(nums.begin(), nums.end(), 0);
        if (T % k != 0)
            return false;
        T /= k;

        used = vector<bool>(nums.size(), false);

        return dfs(nums, 0, k, 0);
    }

    bool dfs(vector<int> &nums, int st, int level, int sum)
    {
        if (level == 0)
            return true;

        if (sum > T)
            return false;
        if (sum == T)
        {
            return dfs(nums, 0, level - 1, 0);
        }

        bool ok = false;
        int last = -1;
        for (int i = st; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            if (nums[i] == last)
                continue;
            used[i] = true;
            last = nums[i];
            ok = dfs(nums, i + 1, level, sum + nums[i]);
            used[i] = false;
            if (ok)
                return true;
        }
        return false;
    }
};
