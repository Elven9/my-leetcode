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
    int findPairs(vector<int> &nums, int diff)
    {
        unordered_map<int, int> MAP;
        for (auto &n : nums)
            MAP[n]++;

        int res = 0;
        for (auto &[k, v] : MAP)
        {
            if (diff == 0)
                res += v >= 2;
            else if (MAP.find(k + diff) != MAP.end())
                res++;
        }

        return res;
    }
};
