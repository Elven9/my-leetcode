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

using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int n = s.size();
        int table[n + 1][26];
        s = "#" + s;

        for (int i = 0; i < 26; i++)
            table[n][i] = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
                table[i][j] = table[i + 1][j];
            table[i][s[i + 1] - 'a'] = i + 1;
        }

        int res = 0;
        for (auto &w : words)
        {
            bool ok = true;
            int i = 0;
            for (auto c : w)
            {
                i = table[i][c - 'a'];
                if (i == -1)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
                res++;
        }

        return res;
    }
};

// brute force method: 1e8 (O(Nn))
// O(Nk) -> 1e5
