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
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1, r = 1e6;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, threshold, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool check(vector<int> &nums, int &th, int &d)
    {
        int sum = 0;
        for (auto &n : nums)
            sum += n / d + (n % d != 0);
        return sum <= th;
    }
};
