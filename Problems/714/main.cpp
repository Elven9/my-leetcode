#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &p, int fee)
    {
        int n = p.size();
        // hold: hold at least one after previous sold
        // sold: sold cur hold at current price
        int hold = INT_MIN / 2, sold = 0;
        for (int i = 0; i < n; i++)
        {
            int h = hold, s = sold;
            hold = max(h, s - p[i]);
            sold = max(s, h + p[i] - fee);
        }
        return sold;
    }
};
