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
    int majorityElement(vector<int> &nums)
    {
        int cand = 0, cnt = 0;
        for (auto &n : nums)
            if (cnt == 0)
            {
                cand = n;
                cnt = 1;
            }
            else
                cnt += n == cand ? 1 : -1;

        return cand;
    }
};
