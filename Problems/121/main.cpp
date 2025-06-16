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
    int maxProfit(vector<int> &prices)
    {
        int res = INT_MIN;
        int future = prices.back();

        for (int i = prices.size() - 2; i >= 0; i--)
        {
            res = max(res, future - prices[i]);
            future = max(future, prices[i]);
        }

        return res > 0 ? res : 0;
    }
};

// greedy to buy and sold, scan from the future
