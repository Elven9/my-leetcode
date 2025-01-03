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

using LL = long long;
class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        LL total = accumulate(nums.begin(), nums.end(), LL(0));

        LL sum = 0, res = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            sum += LL(nums[i]);
            total -= LL(nums[i]);

            res += (sum >= total);
        }

        return res;
    }
};
