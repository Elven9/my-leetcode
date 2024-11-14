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
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        vector<int> SET;

        long long res = 0;
        for (auto &n : nums)
        {
            auto lo = lower_bound(SET.begin(), SET.end(), lower - n);
            auto ho = upper_bound(SET.begin(), SET.end(), upper - n);

            if (!(lo == SET.end() || ho == SET.begin()))
            {
                int lpos = lo - SET.begin();
                int rpos = ho == SET.end() ? SET.size() - 1 : ho - SET.begin() - 1;

                res += rpos - lpos < 0 ? 0 : rpos - lpos + 1;
            }
            SET.push_back(n);
            sort(SET.begin(), SET.end());
        }

        return res;
    }
};

// sorted container, find two number and count

// 0 1 7
