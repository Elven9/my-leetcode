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
        if (sum == T)
        {
            res.push_back(comb);
            return;
        }
        else if (sum > T)
            return;

        for (int i = st; i < C.size(); i++)
        {
            if (i > st && C[i] == C[i - 1])
                continue;

            comb.push_back(C[i]);
            dfs(C, T, i + 1, sum + C[i], comb);
            comb.pop_back();
        }
    }
};

// sort, and check one number in one pass
