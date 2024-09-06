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

using namespace std;

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int l = 1, r = m * n;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (check(m, n, k, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    bool check(int &m, int &n, int &k, int &val)
    {
        int i = m, j = 1;

        int cnt = 0;
        while (i >= 1 && j <= n)
        {
            if (i * j <= val)
            {
                cnt += i;
                j++;
            }
            else
            {
                i--;
            }
        }

        return cnt < k;
    }
};
