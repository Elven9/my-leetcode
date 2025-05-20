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
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> in(n, 0);
        vector<int> out(n + 1, 0);

        for (auto &q : queries)
        {
            in[q[0]]++;
            out[q[1] + 1]++;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += in[i] - out[i];
            if (cnt < nums[i])
                return false;
        }
        return true;
    }
};
