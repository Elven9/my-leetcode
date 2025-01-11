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
    int prefixCount(vector<string> &words, string pref)
    {
        int n = pref.size();

        int res = 0;
        for (auto &w : words)
            res += w.substr(0, n) == pref;

        return res;
    }
};
