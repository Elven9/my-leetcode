#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minSpaceWastedKResizing(vector<int> &nums, int K)
    {
        K++; // K means how many segments, min: 1
        int n = nums.size();
        auto dp = vector<vector<int>>(n + 1, vector<int>(K + 1, INT_MAX / 2));

        // INIT
        for (int i = 0; i <= K; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            int sum = 0, MAX = nums[i - 1];
            for (int j = i; j > 0; j--)
            {
                // last segments
                if (nums[j - 1] > MAX)
                {
                    sum += (i - j) * (nums[j - 1] - MAX);
                    MAX = nums[j - 1];
                }
                else
                    sum += MAX - nums[j - 1];

                for (int k = 1; k <= K; k++)
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + sum);
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};

//         ---
// ---         ------
//    ---

// dp[i][k] = max(nums[i] ~ nums[j]) + dp[j][k-1]
