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
    unordered_map<int, int> p;
    int longestConsecutive(vector<int> &nums)
    {
        for (auto &n : nums)
        {
            if (p.find(n) == p.end())
                p[n] = n;
            else
                continue;

            if (p.find(n + 1) != p.end())
            {
                UNION(n, n + 1);
            }
            if (p.find(n - 1) != p.end())
            {
                UNION(n, n - 1);
            }
        }

        for (auto &n : nums)
            p[n] = FATHER(n);

        int res = 0;
        unordered_map<int, int> cnt;
        for (auto &[k, v] : p)
        {
            cnt[v]++;
            res = max(res, cnt[v]);
        }

        return res;
    }

    int FATHER(int n)
    {
        if (p[n] != n)
        {
            int tmp = FATHER(p[n]);
            p[n] = tmp; // 別浪費這個優化 ww
            return tmp;
        }
        return n;
    }

    void UNION(int a, int b)
    {
        if (p[a] == p[b])
            return;
        int aF = FATHER(a);
        int bF = FATHER(b);
        p[a] = p[b] = max(aF, bF);
    }
};
