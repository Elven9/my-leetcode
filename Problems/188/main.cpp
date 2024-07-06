#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int inf = 1e7; // as long as inf is greater than 1 price limit
        vector<int> buy(k + 1, -inf);
        vector<int> sold(k + 1, -inf);
        buy[0] = 0;
        sold[0] = 0;

        for (auto p : prices)
        {
            auto buy_old = buy;
            auto sold_old = sold;
            for (int j = 1; j <= k; j++)
            {
                // decision -> does this price ok ... ?
                // state -> at which transaction
                buy[j] = max(sold_old[j - 1] - p, buy_old[j]);
                sold[j] = max(buy_old[j] + p, sold_old[j]);
            }
        }
        int ret = -inf;
        for (auto s : sold)
        {
            if (s > ret)
                ret = s;
        }
        if (ret < 0)
            return 0;
        return ret;
    }
};
