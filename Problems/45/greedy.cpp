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
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0, res = 0;
        while (i != n - 1)
        {
            int dist = INT_MIN, next = i;
            for (int len = 1; len <= nums[i]; len++)
            {
                int j = i + len;
                if (j == n - 1)
                {
                    next = j;
                    break;
                }

                if (len + nums[j] > dist)
                {
                    dist = len + nums[j];
                    next = j;
                }
            }
            i = next;
            res++;
        }
        return res;
    }
};

// greedy solution
// maximum reachable selection
//
// i -> j if max(dist, j-i+nums[j]);
// jump + potential jump => reachable definition
