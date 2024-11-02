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
    int findKthNumber(int n, int k)
    {
        return findByPrefix(1, n, k);
    }

    int findByPrefix(int pre, int n, int k)
    {
        for (int i = 0; i < 10; i++)
        {
            if (pre + i > n)
                break;
            int tmp = countPrefix(pre + i, n);
            if (tmp < k)
            {
                k -= tmp;
            }
            else
            {
                if (k - 1 == 0)
                    return pre + i;
                return findByPrefix((pre + i) * 10, n, k - 1);
            }
        }
        return -1;
    }

    long countPrefix(long pre, int &n)
    {
        if (pre > n)
            return 0;
        long cnt = 1;

        long exp = 10;
        while (true)
        {
            long lower = pre * exp;
            long upper = pre * exp + exp - 1;

            if (lower > n)
                break;
            if (lower <= n && upper >= n)
            {
                cnt += n - lower + 1;
                break;
            }
            else
            {
                cnt += exp;
            }
            exp *= 10;
        }

        return cnt;
    }
};
