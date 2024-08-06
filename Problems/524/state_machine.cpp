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

using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dict)
    {
        int n = s.size();
        vector<vector<int>> st(1, vector<int>(26, -1));
        s = "#" + s;
        for (int i = n - 1; i >= 0; i--)
        {
            st.insert(st.begin(), st.front());
            st.front()[s[i + 1] - 'a'] = i + 1;
        }

        string res = "";
        for (auto &d : dict)
        {
            int i = 0;
            bool ok = true;
            for (auto ch : d)
            {
                i = st[i][ch - 'a'];
                if (i == -1)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                if (d.size() > res.size() || (d.size() == res.size() && d < res))
                    res = d;
            }
        }
        return res;
    }
};

// using state machine ww
