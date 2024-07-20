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
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        auto A = vector<pair<int, int>>();
        for (int i = 0; i < n; i++)
            A.push_back({ages[i], scores[i]});
        sort(A.begin(), A.end());

        auto dp = vector<int>(n, 0);

        dp[0] = A[0].second;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[j].first != A[i].first && A[j].second > A[i].second)
                    continue;
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += A[i].second;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// X X X X X i

// dp[i] -> from 0:i, select i, best score
// max(dp[0:n])
//
// all solution space had been check
