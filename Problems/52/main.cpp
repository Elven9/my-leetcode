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
    int totalNQueens(int n)
    {
        vector<int> place;
        return dfs(n, place);
    }

    int dfs(int &n, vector<int> &place)
    {
        if (place.size() == n)
            return 1;

        int res = 0;
        int level = place.size();
        for (int i = 0; i < n; i++)
        {
            bool skip = false;
            for (int j = 0; j < place.size(); j++)
            {
                int idx = place[j];
                if (idx == i || idx == i - (level - j) || idx == i + (level - j))
                {
                    skip = true;
                    break;
                }
            }
            if (skip)
                continue;
            place.push_back(i);
            res += dfs(n, place);
            place.pop_back();
        }

        return res;
    }
};
