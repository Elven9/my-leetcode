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
    int maxCoins(vector<int> &A)
    {
        int n = A.size();
        A.insert(A.begin(), 1);
        A.push_back(1);

        auto dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++)
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MIN;

                for (int k = i; k <= j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + A[k] * A[i - 1] * A[j + 1]);
            }

        return dp[1][n];
    }
};

// only affected by boundrary

// center first -> max(left first, right first)
// center last -> left, right, last ( equal to k )
// left center right
// right center left
// ..
// 9 combination ... wwww

// Define k element as last shot ballon, -> 這個是有涵蓋所有 solution space 的 ！
// for k=i:j
//     dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+k);
