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
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        set<pair<int, int>> SET;
        SET.insert({0, 1});

        long sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            auto it = SET.lower_bound({-(sum - k), INT_MIN});
            if (it != SET.end())
            {
                res = min(res, i - -1 * (*it).second);
            }
            SET.insert({-sum, -i});
        }

        return res == INT_MAX ? -1 : res;
    }
};

// 這個方法，可以確定「有」，但條件是 -(sum-k) <= -prev, 只要大於前值都要考慮，並且沒考慮到越靠近現在的 index

// sum - prev >= k => sum - k >= prev

// 0 2 1 3

// {0, -1}, {1, 1}, {2, 0}, {3, 2}

// {prefix sum, idx}
