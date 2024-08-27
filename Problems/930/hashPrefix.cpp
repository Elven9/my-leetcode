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
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> tb;
        tb[0] = 1;
        int sum = 0, res = 0;
        for (auto &n : nums)
        {
            sum += n;
            res += tb[sum - goal];
            tb[sum]++;
        }
        return res;
    }
};

// Hash + Prefix
