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
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            int j = nums[i] >= 0 ? (i + nums[i]) % n : (i + (nums[i] % n) + n) % n;
            res[i] = nums[j];
        }

        return res;
    }
};
