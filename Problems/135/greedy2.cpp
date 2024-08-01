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
    int candy(vector<int> &R)
    {
        int n = R.size();
        vector<int> candy(n, 0);

        candy[0] = 1;
        for (int i = 1; i < n; i++)
            candy[i] = max(1, R[i] > R[i - 1] ? candy[i - 1] + 1 : INT_MIN);

        for (int i = n - 2; i >= 0; i--)
            candy[i] = max(candy[i], R[i] > R[i + 1] ? candy[i + 1] + 1 : INT_MIN);

        return accumulate(candy.begin(), candy.end(), 0);
    }
};

// two pass scan

// left to right -> check f[i], f[i-1] is valid
// right to left -> check f[i], f[i+1] is valid
