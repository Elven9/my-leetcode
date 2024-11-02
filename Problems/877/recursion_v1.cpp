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
    int scores[2] = {0}; // alice, bob
    int sum = 0;
    unordered_map<string, bool> MAP;
    bool stoneGame(vector<int> &piles)
    {
        sum = accumulate(piles.begin(), piles.end(), 0);

        return dfs(piles, 0, piles.size() - 1, 0);
    }

    bool dfs(vector<int> &piles, int st, int ed, int idx)
    {
        string key = to_string(st) + "-" + to_string(ed);
        if (MAP.find(key) != MAP.end())
            return MAP[key];

        int &score = scores[idx];
        bool ok = false;

        if (ed < st)
        {
            ok = scores[0] > scores[1];
            goto RES;
        }

        score += piles[st];
        ok = dfs(piles, st + 1, ed, !idx);
        score -= piles[st];
        if (!ok)
        {
            ok = true;
            goto RES;
        }

        score += piles[ed];
        ok = dfs(piles, st, ed - 1, !idx);
        score -= piles[ed];
        if (!ok)
            ok = true;

    RES:
        MAP[key] = ok;
        return ok;
    }
};
