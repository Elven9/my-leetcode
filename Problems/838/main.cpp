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
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();

        vector<int> rpos(n, -1e6);
        vector<int> lpos(n, 1e6);

        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != 'L')
                continue;
            int tmp = i - 1;
            while (tmp >= 0 && dominoes[tmp] == '.')
                lpos[tmp--] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != 'R')
                continue;
            int tmp = i + 1;
            while (tmp < n && dominoes[tmp] == '.')
                rpos[tmp++] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
                continue;
            if (lpos[i] == 1e6 && rpos[i] == -1e6)
                continue;
            if (lpos[i] - i == i - rpos[i])
                continue;
            else if (lpos[i] - i > i - rpos[i])
                dominoes[i] = 'R';
            else
                dominoes[i] = 'L';
        }

        return dominoes;
    }
};
