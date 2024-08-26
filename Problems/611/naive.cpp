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
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = 0, res = 0;
        while (r < n)
        {
            if (r <= l)
                r++;
            else if (nums[r] >= nums[l])
            {
                for (int i = r; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                    {
                        if (nums[l] + nums[i] <= nums[j])
                            break;
                        res++;
                    }
                l++;
            }
            else if (nums[r] < nums[l])
                r++;
            else
                l++;
        }

        return res;
    }
};

// 1 1 3 4
