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
        // 如果用純 prefix sum，就需要 O(n^2)
        // 這個 MAP 是用來記錄之前出現過 [sum] 的 frequency
        unordered_map<int, int> MAP;

        MAP[0] = 1;
        int sum = 0, res = 0;
        for (auto &n : nums)
        {
            sum += n;
            if (MAP.find(sum - goal) != MAP.end())
                res += MAP[sum - goal];
            MAP[sum]++;
        }

        return res;
    }
};

// Hash + Prefix
