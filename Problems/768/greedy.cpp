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
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> MIN(n + 2, INT_MIN);
        vector<int> MAX(n + 2, INT_MAX);
        arr.insert(arr.begin(), -1);

        MIN[n + 1] = INT_MAX;
        for (int i = n; i > 0; i--)
            MIN[i] = min(MIN[i + 1], arr[i]);

        MAX[0] = INT_MIN;
        for (int i = 1; i <= n; i++)
            MAX[i] = max(MAX[i - 1], arr[i]);

        int res = 0, last = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (MIN[i] >= last && MAX[i] <= MIN[i + 1])
            {
                res++;
                last = MAX[i];
            }
        }

        return res;
    }
};

// two pass record min max

// MIN= [1, 1, 3, 4, 4]
// MAX= [2, 2, 3, 4 ,4]

// 1 1 1 1 1
// 5 5 5 5 5
