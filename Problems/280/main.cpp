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
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            sort(nums.begin(), nums.end());
        }
        for (int i = 0; i < n - 2; i++)
        {
            helper(nums, i);
        }
    }

    void helper(vector<int> &nums, int idx)
    {
        sort(nums.begin() + idx, nums.begin() + idx + 3);
        if (idx % 2 == 0)
            swap(nums[idx + 1], nums[idx + 2]);
        else
            swap(nums[idx], nums[idx + 1]);
    }
};

// naive solution nlogn sort, and reassign
// 1 2 3 4 5 6

// 三個數字裡面，因為可以相等的關係，一定有個排序
// even idx => small high small
// odd idx => high small high
