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
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), -1);
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] == i)
                continue;

            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);
        }

        // check
        for (int i = 1; i <= n; i++)
            if (nums[i] != i)
                return i;

        return n + 1;
    }
};

// Indexing sort
