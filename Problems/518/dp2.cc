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
    int change(int amount, vector<int> &coins)
    {
        auto dp = vector<int>(amount + 1, 0);
        // sort(coins.begin(), coins.end());
        // no need sort !, 基本上每輪都不會影響到其他 coin 的結果！

        dp[0] = 1;
        for (auto &c : coins)
            for (int i = 1; i <= amount; i++)
                dp[i] += i - c >= 0 ? dp[i - c] : 0;

        return dp[amount];
    }
};
