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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);

        int tmp = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = tmp;
            tmp *= nums[i];
        }

        tmp = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= tmp;
            tmp *= nums[i];
        }

        return res;
    }
};

// simple solution, prefix, suffix -> O(n) but w/ O(n) space

// two pass ... ???
//
