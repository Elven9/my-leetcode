#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int inf = 1e6;
        int n = books.size();
        vector<int> dp(n + 1, inf);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int j = i;
            int wid = 0, MAX = 0;
            while (j > 0)
            {
                wid += books[j - 1][0];
                if (wid > shelfWidth)
                {
                    break;
                }
                MAX = max(MAX, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + MAX);
                j--;
            }
        }
        return dp[n];
    }
};
