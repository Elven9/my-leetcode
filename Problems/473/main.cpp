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
    long T;
    bool makesquare(vector<int> &M)
    {
        sort(M.begin(), M.end(), greater<int>()); // one optimization
        T = accumulate(M.begin(), M.end(), 0);
        if (T % 4 != 0)
            return false;
        T /= 4;

        vector<long> bucket(4, 0);
        return dfs(M, 0, bucket);
    }

    bool dfs(vector<int> &M, int st, vector<long> &bucket)
    {
        if (st == M.size())
        {
            for (auto &b : bucket)
                if (b != T)
                    return false;
            return true;
        }

        bool ok = false;
        for (int i = 0; i < 4; i++)
        {
            if (bucket[i] + M[st] > T)
                continue;
            bucket[i] += M[st];
            ok = dfs(M, st + 1, bucket);
            bucket[i] -= M[st];
            if (ok)
                return true;
        }
        return false;
    }
};
