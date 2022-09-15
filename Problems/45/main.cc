#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // Greedy solution, O(n), O(1)
        // This will work only because we can assume we have one solution.
        int maxReachable = 0, lastJump = 0, i = 0, jump = 0;
        while (lastJump < nums.size() - 1)
        {
            maxReachable = max(maxReachable, i + nums[i]);
            if (lastJump == i)
            {
                lastJump = maxReachable;
                jump++;
            }
            i++;
        }
        return jump;
    }

    int jump_naiveDP(vector<int> &nums)
    {
        // Naive DP solution: O(n^2), O(n)
        // Improved with sliding windows ? It's the same when first element of
        // Energe is too big.

        vector<int> minimaStep(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++)
        {
            int mini = 10001;
            for (int j = 0; j < i; j++)
            {
                if (i - j <= nums[j] && minimaStep[j] + 1 < mini)
                    mini = minimaStep[j] + 1;
            }
            minimaStep[i] = mini;
        }

        return minimaStep.back();
    }
};
