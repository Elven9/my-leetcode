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
    int maxProduct(vector<int> &nums)
    {

        int res = INT_MIN;
        int MAX = 1, MIN = 1;

        for (auto &n : nums)
        {
            int tmp = MAX;
            // n: negative => multiply prev MIN product subarray end at i
            //  : positive => reverse, multiply prev MAX product subarray end at i
            MAX = max({n, n * MAX, n * MIN});
            MIN = min({n, n * tmp, n * MIN});

            res = max(res, MAX);
        }

        return res;
    }
};
