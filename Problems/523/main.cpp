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
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mods;
        mods[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int mod = sum % k;
            if (mods.find(mod) != mods.end())
            {
                if (i - mods[mod] >= 2)
                    return true;
            }
            else
            {
                mods[mod] = i;
            }
        }
        return false;
    }
};
