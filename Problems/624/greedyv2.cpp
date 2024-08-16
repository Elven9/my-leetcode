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
    int maxDistance(vector<vector<int>> &A)
    {
        int res = INT_MIN;
        int MIN = INT_MAX / 2, MAX = INT_MIN / 2;

        for (auto &a : A)
        {
            res = max(res, max(MAX - a.front(), a.back() - MIN));
            MIN = min(MIN, a.front());
            MAX = max(MAX, a.back());
        }

        return res;
    }
};
