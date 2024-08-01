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
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        vector<int> b(n, INT_MAX);

        for (auto &r : restrictions)
            b[r[0] - 1] = r[1];
        b[0] = 0;

        for (int i = 1; i < n; i++)
            b[i] = min(b[i], b[i - 1] + 1);
        for (int i = n - 2; i >= 0; i--)
            b[i] = min(b[i], b[i + 1] + 1);

        return *max_element(b.begin(), b.end());
    }
};

//   1   1     1
// 0 1 2 1 2 3 1
// 0 1 2 1 2 2 1
