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
    int nthUglyNumber(int n)
    {
        vector<int> ugs = {1};

        int dp2 = 0, dp3 = 0, dp5 = 0;
        while (ugs.size() < n)
        {
            int m = min(ugs[dp2] * 2, min(ugs[dp3] * 3, ugs[dp5] * 5));

            if (m == ugs[dp2] * 2)
                dp2++;
            if (m == ugs[dp3] * 3)
                dp3++;
            if (m == ugs[dp5] * 5)
                dp5++;

            ugs.push_back(m);
        }

        return ugs[n - 1];
    }
};

// DP solution !
// maintain three set
//
// by *2
// by *3
// by *5
// try to find minimum from this three generation pattern
//
// we can gen minmum ugly number without sort, (in pq solution)
