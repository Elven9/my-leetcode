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
    int countDays(int days, vector<vector<int>> &M)
    {
        int m = M.size();
        sort(M.begin(), M.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        int res = 0, last = 0, l = 0;
        while (l < m)
        {
            int st = M[l][0], ed = M[l][1];
            while (++l < m && M[l][0] <= ed)
                ed = max(ed, M[l][1]);
            res += st - last - 1;
            last = ed;
        }
        res += days - last;
        return res;
    }
};
