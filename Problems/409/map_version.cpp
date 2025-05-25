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
    int longestPalindrome(string s)
    {
        unordered_map<char, int> freq;
        for (auto &c : s)
            freq[c]++;

        int res = 0;
        bool hasSingle = false;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            res += it->second / 2 * 2;
            hasSingle |= it->second % 2;
        }
        return res + hasSingle;
    }
};
