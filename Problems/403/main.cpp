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
    // 不能用 map 的原因，這個範圍大到會導致 map 的空間會吃超多
    unordered_set<int> S;
    unordered_set<string> failed;
    int T;
    bool canCross(vector<int> &stones)
    {
        for (auto &s : stones)
            S.insert(s);
        T = stones.back();
        return dfs(0, 0);
    }

    bool dfs(int pos, int j)
    {
        if (pos == T)
            return true;
        if (S.find(pos) == S.end())
            return false;

        string key = to_string(pos) + "#" + to_string(j);
        if (failed.find(key) != failed.end())
            return false;

        bool ok = false;
        if (j - 1 > 0)
            ok = dfs(pos + j - 1, j - 1);
        if (!ok && j > 0)
            ok = dfs(pos + j, j);
        if (!ok && j + 1 > 0)
            ok = dfs(pos + j + 1, j + 1);

        if (!ok)
            failed.insert(key);
        return ok;
    }
};

// three points
// 1. using unordered_set for optimized element existing check
// 2. pruning by failed check, not success check
