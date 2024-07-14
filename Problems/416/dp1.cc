#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // Naive solution random selection
        // DP 0-1 knapsack problem on half the sum
        // O(n*sum), O(n*sum) space

        // Find half the sum
        int sum = 0;
        for (auto it = nums.begin(); it != nums.end(); it++)
            sum += *it;
        if (sum % 2 == 1)
            return false;
        sum /= 2;

        vector<vector<bool>> table(nums.size() + 1, vector<bool>(sum + 1, true));
        for (int j = 1; j < sum + 1; j++)
            table[0][j] = false;

        int n = nums.size();
        for (int i = 1; i < n + 1; i++)
        {
            for (int w = 1; w < sum + 1; w++)
            {
                table[i][w] = table[i - 1][w];
                if (w >= nums[i - 1])
                {
                    table[i][w] = table[i][w] || table[i - 1][w - nums[i - 1]];
                }
            }
        }

        return table[n][sum];
    }
};
