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
    int integerReplacement(int n)
    {
        return dfs(n, 0);
    }

    int dfs(long n, int level)
    {
        if (n == 1)
            return level;

        if (n % 2 == 0)
            return dfs(n / 2, level + 1);
        else
            return min(dfs(n + 1, level + 1), dfs(n - 1, level + 1));
    }
};
