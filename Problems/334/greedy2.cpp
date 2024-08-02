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
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> q;

        for (auto &n : nums)
        {
            auto it = lower_bound(q.begin(), q.end(), n);
            if (it == q.end())
                q.push_back(n);
            else
                *it = n;
            if (q.size() == 3)
                return true;
        }
        return false;
    }
};

// LIS = 3 !!!!!
