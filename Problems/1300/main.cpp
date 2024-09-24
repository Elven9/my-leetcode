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
    int findBestValue(vector<int> &arr, int target)
    {
        int l = 0, r = 1e5;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (ok(arr, target, mid))
                r = mid;
            else
                l = mid + 1;
        }

        if (diff(arr, target, l - 1) <= diff(arr, target, l))
            return l - 1;
        return l;
    }

    int diff(vector<int> &arr, int &target, int v)
    {
        long SUM = 0;
        for (auto &n : arr)
            SUM += n > v ? v : n;
        return abs(SUM - target);
    }

    bool ok(vector<int> &arr, int &target, int v)
    {
        long SUM = 0;
        bool altered = false; // corner case
        for (auto &n : arr)
        {
            if (n > v)
            {
                altered = true;
                SUM += v;
            }
            else
                SUM += n;
            if (SUM > target)
                return true;
        }
        return !altered || target - SUM <= 0;
    }
};
