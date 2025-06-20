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
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<int> res;
        vector<int> freq(256, 0);
        int k = 0; // kind
        for (auto &c : p)
            freq[c]++;
        for (auto &f : freq)
            k += f > 0;

        for (int i = 0; i < n; i++)
        {
            if (--freq[s[i]] == 0)
                k--;
            if (i >= m && ++freq[s[i - m]] == 1)
                k++;

            if (k == 0)
                res.push_back(i - m + 1);
        }

        return res;
    }
};

// sliding windows freq check
