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
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 0;

        int l = 0, r = n - 1;
        while (r - 1 >= 0 && arr[r - 1] <= arr[r])
            r--;

        if (r == 0)
            return 0;

        int res = r;
        while (true)
        {
            if (r >= n)
            {
                res = min(res, n - l - 1);
                if (l + 1 >= n || arr[l + 1] < arr[l])
                    break;
                l++;
            }
            else if (arr[l] <= arr[r])
            {
                res = min(res, r - l - 1);
                cout << res << endl;
                if (l + 1 >= n || arr[l + 1] < arr[l])
                    break;
                l++;
            }
            else
                r++;
        }

        return res;
    }
};

// greedy QQ, Not LCS, LIS

// 10,13,17,21                                     13
