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
    vector<vector<int>> merge(vector<vector<int>> &I)
    {
        int n = I.size();
        sort(I.begin(), I.end());
        vector<vector<int>> res;
        int i = 0;
        while (i < n)
        {
            int st = I[i][0], ed = I[i][1];
            i++;
            while (i < n && I[i][0] <= ed)
                ed = max(ed, I[i++][1]);
            res.push_back({st, ed});
        }

        return res;
    }
};
