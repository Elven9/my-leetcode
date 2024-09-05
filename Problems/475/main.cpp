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
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int n = heaters.size();
        int res = INT_MIN;
        int pt = 0;

        for (auto &h : houses)
        {
            while (pt < n && heaters[pt] < h)
                pt++;
            int tmp = INT_MAX;
            if (pt < n)
                tmp = min(tmp, abs(heaters[pt] - h));
            if (pt - 1 >= 0)
                tmp = min(tmp, abs(heaters[pt - 1] - h));
            res = max(res, tmp);
        }
        return res;
    }
};
