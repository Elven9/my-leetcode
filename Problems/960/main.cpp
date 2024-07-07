#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs[0].size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                bool ok = true;
                // This for_each will result in TLE
                // for_each(strs.begin(), strs.end(), [&](string s){ ok &= s[i] >= s[j]; });

                // This one is ok, but still slow
                // for_each(strs.begin(), strs.end(), [&](string &s){ ok &= s[i] >= s[j]; });

                // This one slow too ( so slow .., thanks to auto copy ww )
                // for (auto s: strs) {

                // this one is ok !
                for (auto &s : strs)
                {
                    ok &= s[i] >= s[j];
                    if (!ok)
                        break;
                }
                dp[i] = max(dp[i], ok ? dp[j] + 1 : -1);
            }

        return n - *max_element(dp.begin(), dp.end());
    }
};
