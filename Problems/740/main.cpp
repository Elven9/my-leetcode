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
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), -1);

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            int j = i - 1, cnt = 1;
            while (nums[j] >= nums[i] - 1)
            {
                if (nums[j] == nums[i])
                    cnt++;
                j--;
            }

            dp[i] = max(dp[i - 1], nums[i] * cnt + dp[j]);
        }

        return dp[n];
    }
};

// sort first, to guarentee no aftward effect

// dp[i] -> the maximum number of points you can earn by applying the above operation on nums[0:i]

// dp[i] = max(dp[i-1], delete nums[i]+ dp[j, wher j is the first element that is smaller than nums[i]-1])

// O(n^2)
