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
    int findDuplicate(vector<int> &nums)
    {
        int l = 1, r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    bool check(vector<int> &nums, int T)
    {
        int cnt = 0;
        for (auto &n : nums)
            if (n <= T)
                cnt++;

        return cnt <= T;
    }
};
