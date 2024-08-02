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

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> rm(n); // right max
        vector<int> lm(n); // left min

        lm[0] = nums[0];
        for (int i = 1; i < n; i++)
            lm[i] = min(nums[i], lm[i - 1]);

        rm[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rm[i] = max(nums[i], rm[i + 1]);

        for (int i = 0; i < n; i++)
            if (lm[i] < nums[i] && nums[i] < rm[i])
                return true;

        return false;
    }
};

// brute force not work 1e15
