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
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int v)
    {
        int n = nums.size();
        multiset<long> SET;

        for (int i = 0; i < n; i++)
        {
            if (i > k)
                SET.erase(SET.lower_bound(nums[i - k - 1]));

            auto it = SET.lower_bound((long)nums[i] - v);
            if (it != SET.end() && *it - nums[i] <= v)
                return true;

            SET.insert(nums[i]);
        }
        return false;
    }
};
