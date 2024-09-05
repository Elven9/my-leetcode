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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        auto hi = upper_bound(nums.begin(), nums.end(), target);

        if (lo == nums.end() || *lo != target)
            return {-1, -1};
        return {int(lo - nums.begin()), int(hi - nums.begin()) - 1};
    }
};
