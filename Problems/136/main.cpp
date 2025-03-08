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
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (auto &n : nums)
            res ^= n;

        return res;
    }
};
