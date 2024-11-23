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
    int countValidSelections(vector<int> &nums)
    {
        int n = nums.size();

        auto pre = vector<int>(n, 0);
        auto post = vector<int>(n, 0);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        post[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            post[i] = post[i + 1] + nums[i];

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                continue;

            if (pre[i] == post[i])
                res += 2;
            else if (pre[i] + 1 == post[i] || post[i] + 1 == pre[i])
                res += 1;
        }

        return res;
    }
};

// 39 38
