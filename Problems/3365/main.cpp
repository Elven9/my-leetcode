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
    bool isPossibleToRearrange(string s, string t, int k)
    {
        unordered_map<string, int> MAP;

        int n = s.size(), gap = n / k;
        for (int i = 0; i < n; i += gap)
            MAP[s.substr(i, gap)]++;

        for (int i = 0; i < n; i += gap)
        {
            string tmp = t.substr(i, gap);
            if (MAP[tmp] == 0)
                return false;
            MAP[tmp]--;
        }
        return true;
    }
};
