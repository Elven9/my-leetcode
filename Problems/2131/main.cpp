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
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> freq;
        for (auto &s : words)
            freq[s]++;

        int res = 0;
        bool hasSingle = false;
        for (auto &s : words)
        {
            if (freq[s] == 0)
                continue;
            string rev;
            rev.push_back(s[1]);
            rev.push_back(s[0]);

            if (s == rev)
            {
                res += freq[s] / 2 * 2;
                hasSingle |= freq[s] % 2;
                goto NEXT;
            }
            res += min(freq[s], freq[rev]) * 2;
            freq[rev] = 0;
        NEXT:
            freq[s] = 0;
        }

        return (res + hasSingle) * 2;
    }
};
