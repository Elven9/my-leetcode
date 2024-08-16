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
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int> &C, int T)
    {
        sort(C.begin(), C.end());
        vector<int> comb;
        dfs(C, T, 0, 0, comb);
        return res;
    }
    void dfs(vector<int> &C, int &T, int st, int sum, vector<int> &comb)
    {
        if (st == C.size())
        {
            if (T == sum)
                res.push_back(comb);
            return;
        }
        if (sum > T)
            return;

        if (comb.empty() || C[st] != comb.back())
            dfs(C, T, st + 1, sum, comb);

        comb.push_back(C[st]);
        dfs(C, T, st + 1, sum + C[st], comb);
        comb.pop_back();
    }
};

// sort, and check one number in one pass
