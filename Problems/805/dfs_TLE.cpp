#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int total = 0, n = 0;
    bool splitArraySameAverage(vector<int> &nums)
    {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);

        return dfs(0, 0, 0, nums);
    }

    bool dfs(int i, int sum, int cnt, vector<int> &nums)
    {
        if (i >= nums.size())
            return false;
        if (cnt != 0 && sum * n == total * cnt)
            return true;

        return dfs(i + 1, sum + nums[i], cnt + 1, nums) || dfs(i + 1, sum, cnt, nums);
    }
};

// avg1 * a + avg2 * b = avg * n
//                     = avg * (a + b)

// avg1 == avg2
// avg

// sum / cnt = total / n

// sum * n = total * cnt
