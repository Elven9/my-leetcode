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
    int candy(vector<int> &R)
    {
        int n = R.size();
        vector<int> left(n, 1);

        for (int i = 1; i < n; i++)
            if (R[i] > R[i - 1])
                left[i] = left[i - 1] + 1;

        int res = max(1, left[n - 1]), cur = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (R[i] > R[i + 1])
                cur++;
            else
                cur = 1;

            res += max(cur, left[i]);
        }

        return res;
    }
};

// two scan to check candy .. ?
