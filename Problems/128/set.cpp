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
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0;

        for (auto x : s)
        {
            if (s.find(x - 1) == s.end())
            {
                int cnt = 0;
                while (s.find(x++) != s.end())
                    cnt++;
                res = max(res, cnt);
            }
        }

        return res;
    }
};
