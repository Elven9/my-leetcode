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
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        int n = robot.size(), m = factory.size();

        // necessary .., or it will never reach optimal
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        robot.insert(robot.begin(), 0);
        factory.insert(factory.begin(), {0, 0});

        auto dp = vector<long long>(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i <= m; i++)
        {
            // consider whether or not to place robot to ith factory
            auto dp2 = dp;
            for (int j = 1; j <= n; j++)
            {
                long long dist = 0;

                for (int k = j; k > max(j - factory[i][1], 0); k--)
                {
                    dist += abs(robot[k] - factory[i][0]);
                    // necessary, or it will overflow (also it means it's a unavailable solution)
                    if (dp2[k - 1] == LLONG_MAX)
                        continue;
                    dp[j] = min(dp[j], dist + dp2[k - 1]);
                }
            }
        }

        return dp[n];
    }
};

// dp[i][j]: minimum total distance traveled by robot[0:j] when factory[0:i] are involved

// dp[i][j] = min(robots[j:k] distance to factory[i] + dp[i-1][k-1])
