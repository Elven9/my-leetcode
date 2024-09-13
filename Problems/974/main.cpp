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
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> MAP;

        MAP[0] = 1;
        int sum = 0, res = 0;
        for (auto &n : nums)
        {
            sum += n;
            int tmp = (sum % k + k) % k; // hack ... negative ... 點點點
            if (MAP.find(tmp) != MAP.end())
                res += MAP[tmp];
            MAP[tmp]++;
        }
        return res;
    }
};
