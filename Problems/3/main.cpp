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
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        vector<int> tb(256, 0);

        int l = 0, r = 0; // [l,r)
        int res = 0;
        while (r < n)
        {
            if (tb[s[r]] == 0)
            {
                tb[s[r]]++;
                r++;
                res = max(res, r - l);
            }
            else
            {
                while (s[l] != s[r])
                    tb[s[l++]]--;
                tb[s[l++]]--;
            }
        }

        return res;
    }
};
