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
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> ps(1, 1);

        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            cnt = nums[i] % 2 != nums[i - 1] % 2 ? cnt + 1 : 1;
            ps.push_back(cnt);
        }

        vector<bool> res;
        // interval check
        for (auto &q : queries)
            res.push_back(q[1] - q[0] + 1 <= ps[q[1]]);

        return res;
    }
};

// Original Thought => Get all Intervals, Binary Search on it
// => O(nlogn), it'll work, but too tricky to implement it.
