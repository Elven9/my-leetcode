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
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int cnt[2] = {0, 0};
        for (auto &n : nums)
            cnt[n]++;

        int zcnt = 0;
        for (int i = 0; i < cnt[1]; i++)
            zcnt += nums[i] == 0;
        int min1 = zcnt;
        for (int i = 1; i < n; i++)
        {
            zcnt -= nums[i - 1] == 0;
            zcnt += nums[(i + cnt[1] - 1) % n] == 0;
            min1 = min(min1, zcnt);
        }

        int ocnt = 0;
        for (int i = 0; i < cnt[0]; i++)
            ocnt += nums[i] == 1;
        int min0 = ocnt;
        for (int i = 1; i < n; i++)
        {
            ocnt -= nums[i - 1] == 1;
            ocnt += nums[(i + cnt[0] - 1) % n] == 1;
            min0 = min(min0, ocnt);
        }

        return min(min0, min1);
    }
};

// Three pass greedy
