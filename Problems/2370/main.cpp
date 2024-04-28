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
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        s = '#' + s;
        vector<int> dp(n + 1, 0);
        vector<int> ch(26, 0);
        dp[0] = 0; // For ch array default value 0

        int ret = 0; // ret 就是為啥這題是 Greedy 而不是 DP，DP 比較像是 Build 上去的最佳 Optimal
                     // 這題 dp[i] 是紀錄「結尾為 i 的 subsequene」的最佳解
        for (int i = 1; i <= n; i++)
        {
            char tmp = s[i];
            for (int j = max(0, tmp - 'a' - k); j <= min(25, tmp - 'a' + k); j++)
            {
                dp[i] = max(dp[i], dp[ch[j]] + 1);
            }
            ch[tmp - 'a'] = i;
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};
