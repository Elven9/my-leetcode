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
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 0, r = INT_MAX;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(weights, days, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool check(vector<int> &w, int d, int T)
    {
        int sum = 0, cnt = 0, i = 0;

        while (i < w.size())
        {
            if (sum + w[i] > T)
            {
                if (d == 1 || cnt == 0)
                    return false;
                sum = 0;
                cnt = 0;
                d--;
                continue;
            }
            cnt++;
            sum += w[i++];
        }
        return true;
    }
};
