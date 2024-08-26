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
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = s.size();
        int m = words[0].size();

        unordered_map<string, int> Freq;
        for (auto &w : words)
            Freq[w]++;

        vector<int> res;
        int st = 0;

        while (st < n)
        {
            if (Freq[s.substr(st, m)] > 0)
            {
                auto freq = Freq;
                int cnt = words.size();
                int i = st;

                bool ok = true;
                while (true)
                {
                    if (cnt == 0)
                        break;
                    auto t = s.substr(i, m);
                    if (freq[t] == 0)
                    {
                        ok = false;
                        break;
                    }
                    freq[t]--;
                    cnt--;
                    i += m;
                }
                if (ok)
                    res.push_back(st);
            }
            st++;
        }

        return res;
    }
};

// aba bab
