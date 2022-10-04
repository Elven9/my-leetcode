#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // O(n) solution, O(n) space
        // OMG what a thought, by recording diff between every sum
        // W/ hashmap
        unordered_map<long, int> table;
        long sum = 0;
        int res = 0;
        table[0] = 1;
        for (int n : nums)
        {
            sum += n;
            res += table[sum - k];
            table[sum] += 1;
        }
        return res;
    }
    int subarraySum_TLE(vector<int> &nums, int k)
    {
        // Naive Solution: 1, 2, 3 ..., size scanning, bruteforce windowsing
        // Simple DP ? Rember all calculated sequence: O(n^2)
        // TLE, 72 / 92
        int n = nums.size(), res = 0;
        vector<int> calc(n, 0);
        for (int l = 0; l < n; l++)
        {
            for (int i = 0; i < n - l; i++)
            {
                calc[i] += nums[i + l];
                if (calc[i] == k)
                    res++;
            }
        }
        return res;
    }
};
