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
#include <sstream>
#include <set>
#include <cctype>

using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum = 0, cnt = 0, sacrifice = INT_MAX;
        for (long long n : nums)
        {
            sum += max(n, n ^ k);
            cnt += (n ^ k) > n;
            sacrifice = min(sacrifice, abs(n - (n ^ k)));
        }
        return cnt % 2 ? sum - sacrifice : sum;
    }
};

// greedy ... ?

// .. vlad 大師的 greedy ..... 直接 ignore edges ..
// 這要證明應該也頗麻煩ㄉ
