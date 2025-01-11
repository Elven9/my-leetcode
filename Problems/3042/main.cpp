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
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                res += helper(words[i], words[j]);

        return res;
    }

    bool helper(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size();
        if (m < n)
            return false;
        return s2.substr(0, n) == s1 && s2.substr(m - n, n) == s1;
    }
};
