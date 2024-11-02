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
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> MAP;

        for (int i = 0; i < nums.size(); i++)
        {
            if (MAP.find(nums[i]) != MAP.end())
            {
                if (i - MAP[nums[i]] <= k)
                    return true;
            }
            MAP[nums[i]] = i;
        }
        return false;
    }
};
