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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        int n = gas.size();
        int res = 0, remain = 0;
        for (int i = 0; i < n; i++)
        {
            remain += gas[i] - cost[i];
            if (remain < 0)
            {
                res = i + 1;
                remain = 0;
            }
        }
        return res;
    }
};

// brute force -> start at i, O(n^2)
// it's like 1e10, it's not ok

// greedy
// if A can't reach B, point between A and B can't reach B neither
