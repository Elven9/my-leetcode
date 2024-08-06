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

using namespace std;

class Solution
{
public:
    int rightMin[10005];
    int leftMax[10005];
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), -1e6);

        rightMin[n + 1] = INT_MAX;
        for (int i = n; i > 0; i--)
            rightMin[i] = min(rightMin[i + 1], nums[i]);

        leftMax[0] = INT_MIN;
        for (int i = 1; i <= n; i++)
            leftMax[i] = max(leftMax[i - 1], nums[i]);

        int left = 0, right = n + 1;

        // check left
        while (left + 1 <= n && leftMax[left + 1] <= rightMin[left + 2])
            left++;

        // check right
        while (right - 1 >= 1 && rightMin[right - 1] >= leftMax[right - 2])
            right--;

        if (left == n && right == 1)
            return 0;
        return right - left - 1;
    }
};

// X X X [X X X X X] X X

// left max < center min
// center max < right min

// scan from right to left, record min
// scan from left to right, record max
