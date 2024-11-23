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
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = -1;

        int dupcnt = 0;
        long long res = 0, sum = 0;
        unordered_map<int, int> freq;
        while (true)
        {
            if (r < l || r - l + 1 < k)
            {
                r++;
                freq[nums[r]]++;
                if (freq[nums[r]] == 2)
                    dupcnt++;
                sum += nums[r];
            }
            else
            {
                if (dupcnt == 0)
                    res = max(res, sum);
                sum -= nums[l];
                freq[nums[l]]--;
                if (freq[nums[l]] == 1)
                    dupcnt--;
                l++;

                r++;
                if (r >= n)
                    break;
                sum += nums[r];
                freq[nums[r]]++;
                if (freq[nums[r]] == 2)
                    dupcnt++;
            }
        }

        return res;
    }
};
