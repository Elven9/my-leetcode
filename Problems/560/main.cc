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
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> MAP;
        int sum = 0, res = 0;
        MAP[0]++;
        for (auto &n : nums)
        {
            sum += n;
            res += MAP[sum - k];
            MAP[sum]++;
        }
        return res;
    }
};
