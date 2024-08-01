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

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        int j = n - 1;
        while (j > i && nums[j] <= nums[i])
            j--;

        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
        return;
    }
};

// Lexicographical order
// next permutation => minimun change that can create "greater" (greedy)
//
// permutation
//
// if no greedy -> gen all possible permutation then sort lexicographically
