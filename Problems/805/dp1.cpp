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

class Solution
{
public:
    bool splitArraySameAverage(vector<int> &A)
    {
        int total = accumulate(A.begin(), A.end(), 0);
        int n = A.size();
        if (n == 1)
            return false;
        auto dp = vector<vector<int>>(n + 1, vector<int>(total + 1, 0));
        dp[0][0] = 1;

        int curSum = 0;

        for (auto a : A)
        {
            curSum += a;
            for (int num = n / 2 + 1; num >= 1; num--)
                for (int sum = curSum; sum >= a; sum--)
                {
                    if (dp[num - 1][sum - a] == 1)
                    {
                        dp[num][sum] = 1;
                        if (num != n && total * num == sum * n)
                            return true;
                    }
                }
        }
        return false;
    }
};

// dp[i][cnt][avg] = dp[i-1][cnt-1][avg] || dp[i-1][cnt][avg]

// dp[i-1][cnt-1][avg] -> check if viable,(cnt-1 * avg) + A[i] != cnt*avg -> No

// no avg !, avg can be double

// dp[i][cnt][sum] = dp[i-1][cnt-1][sum-A[i]] || dp[i-1][cnt][sum]

// if ()

// true -> sum / cnt == targetAvg
// dp[0][targetAvg] = true;

// 1e6
