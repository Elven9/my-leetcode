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
    int res = 0, cnt = 0, K, N;
    int findKthNumber(int n, int k)
    {
        K = k;
        N = n;
        dfs(1);
        return res;
    }

    void dfs(long long num)
    {
        for (int i = 0; i < 10; i++)
        {
            long long tmp = num + i;
            if (tmp > N || cnt >= K)
                return;
            cnt++;

            if (cnt == K)
                res = tmp;
            dfs(tmp * 10);
        }
    };
};
