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
    int longestSubstring(string s, int k)
    {
        int res = 0;

        // 限制 windows 中只能有幾種 character，以此限制 sliding windows 的增長
        // 但也因此，要考慮過所有 solution space 的話，就要 1~26 個字母都考慮過
        for (int m = 1; m <= 26; m++)
            res = max(res, helper(s, m, k));

        return res;
    }

    int helper(string &s, int &m, int &k)
    {
        unordered_map<char, int> MAP;
        int j = 0, cnt = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (j < s.size() && MAP.size() <= m)
            {
                MAP[s[j]]++;

                if (MAP[s[j]] == k)
                    cnt++;
                if (MAP.size() == m && cnt == m)
                    res = max(res, j - i + 1);

                j++;
            }

            MAP[s[i]]--;
            if (MAP[s[i]] == k - 1)
                cnt--;
            if (MAP[s[i]] == 0)
                MAP.erase(s[i]);
        }

        return res;
    }
};

// binary search on Value won't works, it can not reduce solution space by half
//
// traditional two pointer won't works neither. It can't not guarentee valid "best" solution is in
// the current window.
