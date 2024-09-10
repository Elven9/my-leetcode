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

using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> MAP;
        int res = 0;
        for (auto &n : nums)
        {
            MAP[n]++;
            int up = MAP[n + 1], down = MAP[n - 1];
            res = max(res, max(up > 0 ? up + MAP[n] : 0, down > 0 ? down + MAP[n] : 0));
        }
        return res;
    }
};

// class Solution
// {
// public:
//     int findLHS(vector<int> &nums)
//     {
//         int n = nums.size();
//         int res = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             int up = 0, down = 0, eq = 0;
//             for (int j = i; j >= 0; j--)
//             {
//                 if (nums[j] == nums[i] + 1)
//                     up++;
//                 else if (nums[j] == nums[i] - 1)
//                     down++;
//                 else if (nums[j] == nums[i])
//                     eq++;
//             }
//             res = max(res, max(up == 0 ? 0 : up + eq, down == 0 ? 0 : down + eq));
//         }
//         return res;
//     }
// };
