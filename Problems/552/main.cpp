#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;

class Solution
{
    LL mod = 1e9 + 7;

public:
    int checkRecord(int n)
    {
        auto dp = vector<vector<LL>>(2, vector<LL>(3, 0));

        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 0;
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;

        for (int i = 1; i < n; i++)
        {
            auto dp2 = dp;
            dp[0][0] = (dp2[0][0] + dp2[0][1] + dp2[0][2]) % mod;                                     // add one more P
            dp[0][1] = dp2[0][0];                                                                     // add one more L
            dp[0][2] = dp2[0][1];                                                                     // add one more L
            dp[1][0] = (dp2[0][0] + dp2[0][1] + dp2[0][2] + dp2[1][0] + dp2[1][1] + dp2[1][2]) % mod; // add one more A to first three state, add one more P to last three state
            dp[1][1] = dp2[1][0];                                                                     // add one more L
            dp[1][2] = dp2[1][1];                                                                     // add one more L
        }

        return (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % mod;
    }
};

// clean state
// dpij -> i how many A, end w/ j consecutive L, number of possible attendance records of length

// --------------------------------------------------------

// dp[i][j]: number of possible attendance records at ith day, the attendance record is jth state ('A', 'L', 'P')

// state: end 'A'                          ---- 1
// state: end 'L', single L, with A        ---- 2
//                         no A            ---- 3
//         'LL' two LL, w/ A               ---- 4
//                         no A            ---- 5
// state: end with A 'P'                   ---- 6
//         no A 'P'                        ---- 7

// 1 = 3 + 5 + 7
// 2 = 1 + 6 + 7
// 3 = 7
