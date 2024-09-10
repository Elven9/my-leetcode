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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> P(26, 0);
        vector<int> S(26, 0);
        for (auto &c : p)
            P[c - 'a']++;

        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {

            S[s[i] - 'a']++;
            if (i >= p.size())
                S[s[i - p.size()] - 'a']--;
            if (S == P)
                res.push_back(i - p.size() + 1);
        }

        return res;
    }
};
