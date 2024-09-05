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
    int splitArray(vector<int> &nums, int k)
    {
        int l = 0, r = INT_MAX;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool check(vector<int> &nums, int k, int T)
    {
        // O(n)
        long sum = 0, cnt = 0, i = 0;
        while (i < nums.size())
        {
            if (sum + nums[i] > T)
            {
                if (cnt == 0 || k == 1)
                    return false;
                sum = 0;
                cnt = 0;
                k--;
                continue;
            }
            cnt++;
            sum += nums[i++];
        }
        return true;
    }
};
