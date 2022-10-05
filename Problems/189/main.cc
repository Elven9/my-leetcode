#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // Simple Optimize: O(n), O(k)
        k %= nums.size();

        if (k == 0)
            return;
        int n = nums.size(), cpy[k], i = n - k, cnt = 0;

        while (i < n)
            cpy[cnt++] = nums[i++];

        i = n - k - 1;
        while (i >= 0)
        {
            nums[i + k] = nums[i];
            i--;
        }

        // Copy back
        i = 0;
        while (i < k)
            nums[i++] = cpy[i];
    }
    void rotate_cpy(vector<int> &nums, int k)
    {
        // Solution 1: Bruteforce, O(kn), space: O(1)
        // Solution 2: Calculate scanning points, copy to new array and copy back
        // O(n), O(n)
        int n = nums.size(), cpy[n], i = 0, cnt = 0;
        k %= nums.size();

        while (i < n - k)
        {
            cpy[i + k] = nums[i];
            i++;
        }
        while (i < n)
            cpy[cnt++] = nums[i++];

        // Copy back
        i = 0;
        while (i < n)
            nums[i++] = cpy[i];
    }
};
