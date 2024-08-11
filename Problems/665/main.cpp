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
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();

        nums.insert(nums.begin(), -1e5 - 5);

        bool modified = false;
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i + 1])
            {
                if (modified)
                    return false;
                if (nums[i + 1] >= nums[i - 1])
                    nums[i] = nums[i - 1];
                else
                    nums[i + 1] = nums[i];
                modified = true;
            }

        return true;
    }
};

// 3 4 2 3

// consider nums[i] & nums[i+1]

// 4 2 1
// 0 2 1

// 1 5 3 7
