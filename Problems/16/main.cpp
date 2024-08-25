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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0, dist = INT_MAX;
        int a = 0;
        while (a < n)
        {
            int l = a + 1, r = n - 1;
            int sum = target - nums[a];

            while (l < r)
            {
                int tmp = target - nums[a] - nums[l] - nums[r];
                if (abs(tmp) < dist)
                {
                    dist = abs(tmp);
                    res = nums[a] + nums[l] + nums[r];
                }
                if (dist == 0)
                    return res;

                if (tmp > 0)
                {
                    l++;
                    while (l < n && nums[l] == nums[l - 1])
                        l++;
                }
                else
                {
                    r--;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        r--;
                }
            }

            a++;
            while (a < n && nums[a] == nums[a - 1])
                a++;
        }

        return res;
    }
};

// a+b+c = target
