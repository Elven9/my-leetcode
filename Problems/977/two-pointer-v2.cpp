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
        int l = 0, r = nums.size() - 1;

        vector<int> res;
        while (l <= r)
        {
            if (abs(nums[l]) > abs(nums[r]))
                res.push_back(pow(nums[l++], 2));
            else
                res.push_back(pow(nums[r--], 2));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
