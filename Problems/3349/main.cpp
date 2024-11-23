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
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int l = i, cnt = k - 1;
            while (l + 1 < n && cnt > 0 && nums[l + 1] > nums[l])
            {
                l++;
                cnt--;
            }
            if (cnt != 0)
                continue;

            l++;
            cnt = k - 1;
            while (l + 1 < n && cnt > 0 && nums[l + 1] > nums[l])
            {
                l++;
                cnt--;
            }
            if (cnt == 0)
                return true;
        }

        return false;
    }
};
