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
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();

        int res = 0, MAX = 0;
        for (int i = 0; i < n; i++)
            if (!grumpy[i])
                res += customers[i];

        int cur = 0;
        for (int i = 0; i < minutes; i++)
            if (grumpy[i])
                cur += customers[i];

        MAX = cur;
        for (int i = minutes; i < n; i++)
        {
            cur -= grumpy[i - minutes] ? customers[i - minutes] : 0;
            cur += grumpy[i] ? customers[i] : 0;
            MAX = max(MAX, cur);
        }

        return res + MAX;
    }
};
