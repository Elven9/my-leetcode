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
        vector<int> freq(256, INT_MIN);
        int CNT = 0;
        for (auto &c : t)
        {
            if (freq[c] == INT_MIN)
            {
                freq[c] = 0;
                CNT++;
            }
            freq[c]++;
        }

        pair<int, int> res = {-1, n};
        int l = 0, r = 0; // [l,r)
        while (r < n || CNT == 0)
        {
            if (CNT != 0)
            {
                int &f = freq[s[r]];
                if (f != INT_MIN)
                {
                    f--;
                    if (f == 0)
                        CNT--;
                }
                r++;
            }
            else
            {
                if (res.second - res.first > r - l)
                    res = {l, r};
                int &f = freq[s[l]];
                if (f != INT_MIN)
                {
                    f++;
                    if (f == 1)
                        CNT++;
                }
                l++;
            }
        }
        if (res.first == -1)
            return "";
        return s.substr(res.first, res.second - res.first);
    }
};
