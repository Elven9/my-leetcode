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
    long mod = 1e9 + 7;
    long freq[26] = {0};
    long dup[26] = {0};
    int lengthAfterTransformations(string s, int t)
    {
        for (auto &c : s)
            freq[c - 'a']++;

        while (t-- > 0)
        {
            for (int i = 0; i < 25; i++)
                dup[i + 1] = freq[i];
            dup[0] = freq[25];
            dup[1] = (dup[1] + freq[25]) % mod;

            for (int i = 0; i < 26; i++)
                freq[i] = dup[i];
        }

        long res = 0;
        for (int i = 0; i < 26; i++)
            res = (res + freq[i]) % mod;

        return res;
    }
};
