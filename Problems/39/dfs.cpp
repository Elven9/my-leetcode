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
    vector<vector<int>> combinationSum(vector<int> &C, int T)
    {
        vector<int> comb;
        dfs(C, T, 0, 0, comb);
        return res;
    }

    void dfs(vector<int> &C, int T, int st, int sum, vector<int> comb)
    {
        if (sum == T)
        {
            res.push_back(comb);
            return;
        }
        else if (sum > T)
            return;

        for (int i = st; i < C.size(); i++)
        {
            comb.push_back(C[i]);
            dfs(C, T, i, sum + C[i], comb);
            comb.pop_back();
        }
    }
};
