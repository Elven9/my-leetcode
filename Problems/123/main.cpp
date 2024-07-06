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
    int maxProfit(vector<int> &prices)
    {
        int inf = 1e7;
        int buy1 = -inf, sold1 = -inf, buy2 = -inf, sold2 = -inf;
        for (auto p : prices)
        {
            int oldBuy1 = buy1;
            int oldSold1 = sold1;
            int oldBuy2 = buy2;
            buy1 = max(-p, buy1);
            sold1 = max(oldBuy1 + p, sold1);
            buy2 = max(oldSold1 - p, buy2);
            sold2 = max(oldBuy2 + p, sold2);
        }
        return max({0, sold1, sold2});
    }
};
