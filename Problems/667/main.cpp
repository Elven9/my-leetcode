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
    vector<int> constructArray(int n, int k)
    {
        vector<int> res;

        for (int i = 0; i <= k; i++)
            res.push_back(i % 2 == 0 ? k + 1 - i / 2 : i / 2 + 1);

        reverse(res.begin(), res.end());
        for (int i = k + 2; i <= n; i++)
            res.push_back(i);

        return res;
    }
};

// 1 2 3 4 5     k = 4

// 5 1 4 2 3

// k = 2

// 3 1 2

// k = 3
// 4 1 3 2
