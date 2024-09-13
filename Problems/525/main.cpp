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
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> MAP;

        MAP[0] = -1;

        int sum = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i] == 1 ? 1 : -1;
            if (MAP.find(sum) != MAP.end())
            {
                res = max(res, i - MAP[sum]);
            }
            else
            {
                MAP[sum] = i;
            }
        }
        return res;
    }
};
