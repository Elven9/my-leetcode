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
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> buf;
        dfs(1, n, k, buf);
        return res;
    }

    void dfs(int st, int n, int k, vector<int> &buf)
    {
        if (k == 0)
        {
            res.push_back(buf);
            return;
        }

        for (int i = st; i <= n; i++)
        {
            buf.push_back(i);
            dfs(i + 1, n, k - 1, buf);
            buf.pop_back();
        }
    }
};
