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
    int longestPalindrome(string s)
    {
        vector<int> tb(256, 0);
        for (auto &c : s)
            tb[c]++;

        int res = 0;
        bool hasOnly = false;
        for (auto &f : tb)
        {
            hasOnly |= f % 2 == 1;
            res += f / 2 * 2;
        }
        return res + hasOnly;
    }
};
