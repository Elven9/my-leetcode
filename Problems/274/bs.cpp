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
    int hIndex(vector<int> &C)
    {
        int l = 0, r = C.size();

        while (l < r)
        {
            int mid = r - (r - l) / 2;

            if (check(C, mid))
                l = mid;
            else
                r = mid - 1;
        }
        // 這題跟 lc. 275 比起來，是一定會找到答案的
        return l;
    }

    bool check(vector<int> &C, int val)
    {
        int cnt = 0;
        for (auto &c : C)
            if (c >= val)
                cnt++;
        return cnt >= val;
    }
};
