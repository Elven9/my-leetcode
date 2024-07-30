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

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        auto a = vector<int>(n + 1, 0);
        auto b = vector<int>(n + 1, 0);
        s = "#" + s;

        for (int i = 1; i <= n; i++)
        {
            a[i] = a[i - 1] + (s[i] == 'a');
            b[i] = b[i - 1] + (s[i] == 'b');
        }

        // check result
        int res = INT_MAX;
        for (int i = 1; i <= n; i++)
            res = min(res, b[i] - (s[i] == 'b') + a[n] - a[i]);
        return res;
    }
};

// cnt a, b first, prefix sum
// scan n -> check every possible solution space
