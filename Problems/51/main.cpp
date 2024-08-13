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
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> comb;
        dfs(n, 0, comb);
        return res;
    }

    void dfs(int &n, int level, vector<int> &comb)
    {
        // stop
        if (level == n)
        {
            vector<string> tmp;
            for (auto &idx : comb)
            {
                stringstream ss;
                for (int j = 0; j < n; j++)
                {
                    if (idx == j)
                        ss << "Q";
                    else
                        ss << '.';
                }
                tmp.push_back(ss.str());
            }
            res.push_back(tmp);
            return;
        }

        // search
        for (int i = 0; i < n; i++)
        {
            // pruning
            bool skip = false;
            for (int j = 0; j < comb.size(); j++)
            {
                int idx = comb[j];
                if (idx == i || idx == i - (level - j) || idx == i + (level - j))
                {
                    skip = true;
                    break;
                }
            }
            if (skip)
                continue;

            comb.push_back(i);
            dfs(n, level + 1, comb);
            comb.pop_back();
        }
    }
};
