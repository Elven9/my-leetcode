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
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int median = 0, limit = (grid.size() * grid[0].size()) / 2 + 1;

        // method 1: use less memory than method 2
        // multiset<int> SET;
        // for (auto &col: grid)
        //     for (auto &n: col) {
        //         SET.insert(n);
        //         if (SET.size() > limit) SET.erase(prev(SET.end()));
        //     }
        // median = *SET.rbegin();

        // method 2: use more memory, but faster
        vector<int> nums;
        for (auto &col : grid)
            for (auto &n : col)
                nums.push_back(n);
        sort(nums.begin(), nums.end());
        median = nums[limit - 1];

        int res = 0;
        for (auto &col : grid)
            for (auto &n : col)
            {
                int dist = abs(n - median);
                if (dist % x != 0)
                    return -1;
                res += dist / x;
            }

        return res;
    }
};
