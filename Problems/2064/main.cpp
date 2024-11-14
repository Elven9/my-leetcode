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
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int l = 1, r = INT_MAX;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (!check(quantities, n, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return r;
    }

    bool check(vector<int> &quantities, long long n, int seg)
    {
        long long cnt = 0;
        for (auto &q : quantities)
            cnt += q / seg + (q % seg != 0);

        return cnt <= n;
    };
};

// O(mn) backtracking won't works;
//
// binary search by value
