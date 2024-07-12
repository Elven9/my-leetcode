#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;

class Solution
{
public:
    LL mod = 1e9 + 7;
    int numberOfArrays(string s, int k)
    {
        int n = s.size();
        vector<LL> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            LL x = 0;
            for (int j = i; j >= max(1, i - 10); j--)
            {
                // check
                if (s[j - 1] == '0')
                    continue;
                // 這個寫起來超快，但速度超慢（copy, convert) 等等
                // if (atoll(s.substr(j-1, i-j+1).c_str()) > k) break;
                x = x + pow(10, i - j) * (s[j - 1] - '0');
                if (x > k)
                    break;
                dp[i] = (dp[i] + dp[j - 1]) % mod;
            }
        }
        return dp[n];
    }
};

// dfs optimization with overlapping subproblem
// X X X j X X i
//
// s[j:i] as a int ( below K )
// dp[i] += (dp[j-1] all possible solution)
// no illegal number exists, one concate one
