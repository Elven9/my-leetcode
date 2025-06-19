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
    string minWindow(string s, string t)
    {
        int n = s.size();
        vector<int> freq(256, 0);
        int k = 0;
        for (auto &c : t)
            freq[c]++;
        for (auto &f : freq)
            k += f != 0;

        int l = 0, r = 0, len = INT_MAX;
        string res = "";
        while (r < n)
        {
            freq[s[r]]--;
            if (freq[s[r]] == 0)
                k--;

            if (k == 0)
            {
                // shrink left
                while (freq[s[l]] < 0)
                    freq[s[l++]]++;
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    res = s.substr(l, len);
                }
                freq[s[l++]]++;
                k++;
            }
            r++;
        }
        return res;
    }
};

// sliding windows
