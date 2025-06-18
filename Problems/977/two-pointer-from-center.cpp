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
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return {nums[0] * nums[0]};

        int r = 1, l = -1;
        while (r < n && abs(nums[r - 1]) >= abs(nums[r]))
            r++;
        l = r - 1;

        vector<int> res;
        while (r < n || l >= 0)
        {
            int tmp = INT_MAX;
            if (l >= 0)
                tmp = min(tmp, abs(nums[l]));
            if (r < n)
                tmp = min(tmp, abs(nums[r]));

            res.push_back(tmp * tmp);
            if (l >= 0 && tmp == abs(nums[l]))
                l--;
            else if (r < n && tmp == abs(nums[r]))
                r++;
        }
        return res;
    }
};

// simple solution O(nlogn)

// O(n) solution: find the center and start with two pointer
