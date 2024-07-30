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
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;
        while (i != n - 1)
        {
            if (nums[i] == 0)
                return false;
            int dist = INT_MIN, next = i;
            for (int len = 1; len <= nums[i]; len++)
            {
                int j = i + len;
                if (j == n - 1)
                    return true;

                if (len + nums[j] > dist)
                {
                    dist = len + nums[j];
                    next = j;
                }
            }
            i = next;
        }
        return true;
    }
};

// greedy solution
// local optimal: next index, whose potential distance is maximum

// i -> j if max(dist, j-i+nums[j]);
