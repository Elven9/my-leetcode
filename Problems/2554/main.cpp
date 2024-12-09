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
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        sort(banned.begin(), banned.end());

        int res = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            auto it = lower_bound(banned.begin(), banned.end(), i);
            if (it != banned.end() && *it == i)
                continue;
            if (sum + i > maxSum)
                break;

            res++;
            sum += i;
        }

        return res;
    }
};
