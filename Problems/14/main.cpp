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
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        int p = 0;
        while (true)
        {
            bool ok = true;
            if (p >= strs[0].size())
                break;
            for (int i = 1; i < n; i++)
            {
                if (p >= strs[i].size() || strs[i][p] != strs[i - 1][p])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                p++;
            else
                break;
        }
        return strs[0].substr(0, p);
    }
};
