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
    int maxProfit(vector<int> &p)
    {
        if (p.size() == 1)
            return 0;
        int buy = INT_MIN, sold = 0, cooled = 0; // cooled -> after 0 or multiple sold
        for (int i = 0; i < p.size(); i++)
        {
            int b = buy, s = sold, c = cooled;
            buy = max(b, c - p[i]);
            sold = b + p[i];
            cooled = max(c, s);
        }
        return max(cooled, sold);
    }
};
