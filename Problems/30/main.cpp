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

        for (int st = 0; st < m; st++)
        {
            // 用 copy 真的慢超級多 www
            // auto freq=Freq; 然後用扣的，真的差超多點點點
            unordered_map<string, int> freq;
            int cnt = words.size();
            int l = st, r = st;

            while (r < n)
            {
                string ss = s.substr(r, m);
                if (Freq.find(ss) == Freq.end())
                {
                    freq.clear();
                    cnt = words.size();
                    r += m;
                    l = r;
                }
                else if (freq[ss] == Freq[ss])
                {
                    freq[s.substr(l, m)]--;
                    l += m;
                    cnt++;
                }
                else if (freq[ss] < Freq[ss])
                {
                    freq[ss]++;
                    r += m;
                    cnt--;
                }
                if (cnt == 0)
                {
                    res.push_back(l);
                    freq[s.substr(l, m)]--;
                    l += m;
                    cnt++;
                }
            }
        }
        return res;
    }
};

// aba bab
